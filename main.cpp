#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "save.h"
using namespace std;

#define VERSION "1.8.2"

static void sleep_ms(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

static void next_day(int& y, int& m, int& d) {
    int dim[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (y % 4 == 0) dim[2] = 29;
    if (++d > dim[m]) { d = 1; if (++m > 12) { m = 1; y++; } }
}

static void do_draw(string& xk, int& t) {
    struct Card { int lo, hi; const char* name; const char* grade; int t_bonus; };
    static const Card cards[] = {
        {1,   1,    "H100",       "SSSSS", 10000},
        {10,  15,   "Tesla H800", "SSSS",   9500},
        {16,  20,   "RTX5090",   "SSS",    9000},
        {21,  25,   "RTX5080",   "SSS",    8000},
        {26,  30,   "RTX4090",   "SSS",    8000},
        {31,  40,   "RTX4080",   "SS",     7300},
        {41,  70,   "RTX3090",   "SS",     7000},
        {71,  140,  "RTX3070",   "S",      6000},
        {141, 240,  "RTX2090",   "S",      6000},
        {241, 1240, "RTX2070",   "A",      4500},
        {1241,2240, "RTX1090",   "A",      4500},
        {2241,4238, "RTX1070",   "B",      3000},
        {4239,4239, "RX6000XT",  "SSS+",   9900},
        {4240,4240, "RX6000",    "SSS",    9000},
        {4241,4340, "RX5000",    "SS",     7500},
        {4341,4440, "RX4000",    "S",      6000},
    };
    int r = rand() % 10000;
    for (auto& c : cards) {
        if (r >= c.lo && r <= c.hi) {
            cout << "Got: " << c.name << " [" << c.grade << "]" << endl;
            xk = c.name;
            t = max(0, t - c.t_bonus);
            return;
        }
    }
    if (r >= 4441 && r <= 9990) cout << "Got: Money*6666 Bitcoin*6" << endl;
    else cout << "Nothing this time." << endl;
}

int main()
{
    srand((unsigned)time(0));

    int y = 2022, m = 1, d = 1;
    int t = 10000;
    int c = 0, b_yuan = 36000;
    char in;
    long long success = 0, fail = 0;
    long long w = 0, wh = 100, rmb = 0, um = 0, xkm = 1;
    bool mail[3] = {true, false, false};
    string xk = "GTX1060";

    cout << "=Disclaimer=" << endl;
    cout << "Mining Simulator " VERSION " by XINGJI Interactive Software." << endl;
    cout << "https://www.xingjisoft.top/" << endl;
    sleep_ms(3000);

    cout << "| Loading... |" << flush;
    load_game(rmb, success, xkm, xk);
    sleep_ms(1000);
    cout << "\r| Ready!     |" << endl;
    cout << "|=== Mining Simulator " VERSION " - XINGJI ===|" << endl;
    sleep_ms(1500);
    for (int i = 0; i < 40; i++) cout << '\n';

    while (true)
    {
        if (rmb < 0 && rmb >= -10000)
            cout << "[MXUSB] Free overdraft active (limit: -10000 RMB)" << endl;
        else if (rmb < -10000) {
            cout << "[MXUSB] Overdraft exceeded. Daily interest charged." << endl;
            um += (-rmb) / 100;
        }

        cout << "\n* Mining Simulator " VERSION " *" << endl;
        cout << " A.Start  B.Exit  C.Settings  D.Shop  E.Mail" << endl;
        cin >> in; in = (char)toupper(in);

        if (in == 'A') {
            c = 1;
        } else if (in == 'B') {
            cout << "Saving..." << endl;
            save_game(rmb, success, xkm, xk);
            sleep_ms(1000);
            return 0;
        } else if (in == 'C') {
            c = 2;
        } else if (in == 'D') {
            cout << "A.Draw (10000 RMB/time)  B.Back" << endl;
            cin >> in; in = (char)toupper(in);
            if (in == 'A') {
                if (rmb < 10000) cout << "Not enough money!" << endl;
                else { rmb -= 10000; do_draw(xk, t); }
            }
        } else if (in == 'E') {
            if (mail[0]) {
                cout << "[New Mail] Welcome! Reward: 1,000,000 RMB. A to claim." << endl;
                cin >> in;
                rmb += 1000000;
                mail[0] = false;
                cout << "Claimed!" << endl;
            } else {
                cout << "No new mail." << endl;
            }
        }

        if (c == 2) {
            cout << "A.Auto-pause  B.Changelog  C.About  D.Loan  E.Version" << endl;
            cin >> in; in = (char)toupper(in);
            if (in == 'A') { cin >> wh; }
            else if (in == 'B') {
                cout << "1.8.2 - Code refactor, cross-platform" << endl;
                cout << "1.8.0 - Open source" << endl;
                cout << "1.7.0 - Multi-language, save system" << endl;
            }
            else if (in == 'C') { cout << "Mining Simulator by XINGJI Interactive Software" << endl; }
            else if (in == 'D') {
                long long amount;
                cout << "Loan amount (1%/day interest): ";
                cin >> amount;
                um += amount; rmb += amount;
            }
            else if (in == 'E') { cout << "Version: " VERSION << endl; }
            c = 0;
        }

        while (c == 1) {
            int l = rand() % 500 + 1;
            w++;
            next_day(y, m, d);
            if (um > 0) um += um / 100;

            if (w % l == 0) {
                success++;
                cout << " #### " << y << "/" << m << "/" << d
                     << " | OK   | S:" << success << " F:" << fail << " ####" << endl;
            } else {
                fail++;
                cout << " **** " << y << "/" << m << "/" << d
                     << " | FAIL | S:" << success << " F:" << fail << " ****" << endl;
            }
            sleep_ms(t);

            if (w == wh) {
                rmb = success * b_yuan;
                cout << "\nTotal: " << success << " BTC = " << rmb << " RMB | Debt: " << um << " RMB" << endl;
                cout << " A.Continue  B.Menu  C.Repay debt" << endl;
                cin >> in; in = (char)toupper(in);
                if      (in == 'B') { c = 0; }
                else if (in == 'C') {
                    if (rmb >= um) { rmb -= um; um = 0; cout << "Debt repaid. Balance: " << rmb << " RMB" << endl; }
                    else cout << "Insufficient balance." << endl;
                    sleep_ms(1000);
                    c = 0;
                }
                w = 0;
            }
        }
    }
}
