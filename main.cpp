#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "save.h"
#include "i18n.h"
using namespace std;

static void sleep_ms(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

static void next_day(int& y, int& m, int& d) {
    int dim[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (y % 4 == 0) dim[2] = 29;
    if (++d > dim[m]) { d = 1; if (++m > 12) { m = 1; y++; } }
}

static void do_draw(string& xk, int& t, const Lang& L) {
    struct Card { int lo, hi; const char* name; const char* grade; int t_bonus; };
    static const Card cards[] = {
        {1,   1,    "H100",       "SSSSS", 10000},
        {10,  15,   "Tesla H800", "SSSS",   9500},
        {16,  20,   "RTX5090",    "SSS",    9000},
        {21,  25,   "RTX5080",    "SSS",    8000},
        {26,  30,   "RTX4090",    "SSS",    8000},
        {31,  40,   "RTX4080",    "SS",     7300},
        {41,  70,   "RTX3090",    "SS",     7000},
        {71,  140,  "RTX3070",    "S",      6000},
        {141, 240,  "RTX2090",    "S",      6000},
        {241, 1240, "RTX2070",    "A",      4500},
        {1241,2240, "RTX1090",    "A",      4500},
        {2241,4238, "RTX1070",    "B",      3000},
        {4239,4239, "RX6000XT",   "SSS+",   9900},
        {4240,4240, "RX6000",     "SSS",    9000},
        {4241,4340, "RX5000",     "SS",     7500},
        {4341,4440, "RX4000",     "S",      6000},
    };
    int r = rand() % 10000;
    for (auto& c : cards) {
        if (r >= c.lo && r <= c.hi) {
            cout << L.draw_got << c.name << " [" << c.grade << "]" << endl;
            xk = c.name;
            t = max(0, t - c.t_bonus);
            return;
        }
    }
    if (r >= 4441 && r <= 9990) cout << L.draw_bonus << endl;
    else cout << L.draw_nothing << endl;
}

int main()
{
    const Lang& L = get_lang();
    srand((unsigned)time(0));

    int y = 2022, m = 1, d = 1;
    int t = 10000, c = 0, b_yuan = 36000;
    char in;
    long long success = 0, fail = 0;
    long long w = 0, wh = 100, rmb = 0, um = 0, xkm = 1;
    bool mail[3] = {true, false, false};
    string xk = "GTX1060";

    cout << L.disclaimer << endl;
    sleep_ms(3000);

    cout << L.loading << flush;
    load_game(rmb, success, xkm, xk);
    sleep_ms(1000);
    cout << "\r" << L.ready << endl;
    cout << "|=== Mining Simulator " VERSION " - XINGJI ===|" << endl;
    sleep_ms(1500);
    for (int i = 0; i < 40; i++) cout << '\n';

    while (true)
    {
        if (rmb < 0 && rmb >= -10000)
            cout << L.overdraft_free << endl;
        else if (rmb < -10000) {
            cout << L.overdraft_over << endl;
            um += (-rmb) / 100;
        }

        cout << "\n" << L.menu << endl;
        cout << L.menu_prompt << endl;
        cin >> in; in = (char)toupper(in);

        if (in == 'A') {
            c = 1;
        } else if (in == 'B') {
            cout << L.saving << endl;
            save_game(rmb, success, xkm, xk);
            sleep_ms(1000);
            return 0;
        } else if (in == 'C') {
            c = 2;
        } else if (in == 'D') {
            cout << L.draw_menu << endl;
            cin >> in; in = (char)toupper(in);
            if (in == 'A') {
                if (rmb < 10000) cout << L.not_enough << endl;
                else { rmb -= 10000; do_draw(xk, t, L); }
            }
        } else if (in == 'E') {
            if (mail[0]) {
                cout << L.mail_new << endl;
                cin >> in;
                rmb += 1000000;
                mail[0] = false;
                cout << L.mail_claimed << endl;
            } else {
                cout << L.mail_none << endl;
            }
        }

        if (c == 2) {
            cout << L.settings_menu << endl;
            cin >> in; in = (char)toupper(in);
            if      (in == 'A') { cin >> wh; }
            else if (in == 'B') { cout << L.changelog << endl; }
            else if (in == 'C') { cout << L.about << endl; }
            else if (in == 'D') {
                long long amount;
                cout << L.loan_prompt;
                cin >> amount;
                um += amount; rmb += amount;
            }
            else if (in == 'E') { cout << L.version_str << endl; }
            c = 0;
        }

        while (c == 1) {
            int l = rand() % 500 + 1;
            w++;
            next_day(y, m, d);
            if (um > 0) um += um / 100;

            char buf[128];
            if (w % l == 0) {
                success++;
                snprintf(buf, sizeof(buf), L.mining_ok, y, m, d, success, fail);
            } else {
                fail++;
                snprintf(buf, sizeof(buf), L.mining_fail, y, m, d, success, fail);
            }
            cout << buf << endl;
            sleep_ms(t);

            if (w == wh) {
                rmb = success * b_yuan;
                snprintf(buf, sizeof(buf), L.round_end, success, rmb, um);
                cout << buf << endl;
                cout << L.round_menu << endl;
                cin >> in; in = (char)toupper(in);
                if (in == 'B') { c = 0; }
                else if (in == 'C') {
                    if (rmb >= um) {
                        rmb -= um; um = 0;
                        snprintf(buf, sizeof(buf), L.debt_repaid, rmb);
                        cout << buf << endl;
                    } else {
                        cout << L.debt_insuf << endl;
                    }
                    sleep_ms(1000);
                    c = 0;
                }
                w = 0;
            }
        }
    }
}
