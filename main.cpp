#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "save.h"
using namespace std;

static void sleep_ms(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

// Advance date by one day
static void next_day(int& y, int& m, int& d) {
    int days_in_month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (y % 4 == 0) days_in_month[2] = 29;
    if (++d > days_in_month[m]) { d = 1; if (++m > 12) { m = 1; y++; } }
}

int main()
{
    int y = 2022, m = 1, d = 1;
    int i = 0, n = 0, s = 0;
    int t = 10000, l = 72, bd = 0, inm;
    int c = 0, xkm = 1, b_yuan = 36000;
    char in;
    long long w = 0, wh = 100, rmb = 0, um = 0;
    int mail[100] = {1,1,1};
    string xk = "GTX1060";

    cout << "=Disclaimer=" << endl;
    cout << "Mining Simulator is developed by XINGJI Interactive Software. All rights reserved." << endl;
    cout << "Official site: https://www.xingjisoft.top/" << endl;
    sleep_ms(3000);

    cout << "| Loading... |";
    load_game(rmb, s, xkm, xk);
    sleep_ms(2000);
    cout << "\r| Ready!     |" << endl;

    cout << "|=========Mining Simulator 1.8.1=========|" << endl;
    cout << "|   P O W E R E D   B Y   X I N G J I   |" << endl;
    sleep_ms(1500);
    for (int i = 0; i < 40; i++) cout << endl;

    in = 0;
    while (true)
    {
        cout << "*******************************************" << endl;
        cout << "*     Mining Simulator 1.8.1 - XINGJI    *" << endl;
        cout << "*******************************************" << endl;
        cout << " A.Start   B.Exit   C.Settings   D.Shop   E.Mail" << endl;
        cin >> in;

        if (in == 'A' || in == 'a')
        {
            c = 1;
        }
        else if (in == 'B' || in == 'b')
        {
            cout << "Saving..." << endl;
            save_game(rmb, s, xkm, xk);
            sleep_ms(1000);
            return 0;
        }
        else if (in == 'C' || in == 'c')
        {
            c = 2;
        }
        else if (in == 'D' || in == 'd')
        {
            cout << "A.Draw (10000 RMB/time)   B.Back" << endl;
            cin >> in;
            if (in == 'A' || in == 'a')
            {
                if (rmb < 10000) { cout << "Not enough money!" << endl; }
                else
                {
                    rmb -= 10000;
                    srand((int)time(0));
                    int xkr = rand() % 10000;
                    struct { int lo, hi; const char* name; const char* grade; int t_bonus; } cards[] = {
                        {1,   1,    "H100",      "SSSSS", 10000},
                        {10,  15,   "Tesla H800","SSSS",  9500},
                        {16,  20,   "RTX5090",   "SSS",   9000},
                        {21,  25,   "RTX5080",   "SSS",   8000},
                        {26,  30,   "RTX4090",   "SSS",   8000},
                        {31,  40,   "RTX4080",   "SS",    7300},
                        {41,  70,   "RTX3090",   "SS",    7000},
                        {71,  140,  "RTX3070",   "S",     6000},
                        {141, 240,  "RTX2090",   "S",     6000},
                        {241, 1240, "RTX2070",   "A",     4500},
                        {1241,2240, "RTX1090",   "A",     4500},
                        {2241,4238, "RTX1070",   "B",     3000},
                        {4239,4239, "RX6000XT",  "SSS+",  9900},
                        {4240,4240, "RX6000",    "SSS",   9000},
                        {4241,4340, "RX5000",    "SS",    7500},
                        {4341,4440, "RX4000",    "S",     6000},
                    };
                    bool found = false;
                    for (auto& c : cards) {
                        if (xkr >= c.lo && xkr <= c.hi) {
                            cout << "Got: " << c.name << " [" << c.grade << "]" << endl;
                            xk = c.name;
                            t = max(0, t - c.t_bonus);
                            found = true; break;
                        }
                    }
                    if (!found && xkr >= 4441 && xkr <= 9990)
                        cout << "Got: Money*6666 Bitcoin*6" << endl;
                    else if (!found)
                        cout << "Nothing this time." << endl;
                }
            }
        }
        else if (in == 'E' || in == 'e')
        {
            if (mail[0] == 1)
            {
                cout << "[New Mail] Welcome to Mining Simulator!" << endl;
                cout << "Claim reward: Money*1000000. Press A to claim." << endl;
                cin >> in;
                rmb += 1000000;
                mail[0] = 0;
                cout << "Claimed!" << endl;
            }
            else cout << "No new mail." << endl;
        }

        if (rmb < 0 && rmb >= -10000)
            cout << "[MXUSB] Free overdraft active (limit: -10000)" << endl;
        else if (rmb < -10000) {
            cout << "[MXUSB] Overdraft exceeded, interest charged at 1%/day." << endl;
            um += (-rmb) / 100;
        }

        if (c == 2)
        {
            cout << "A.Auto-pause   B.Changelog   C.About   D.Language   E.Loan   F.Version" << endl;
            cin >> in;
            if (in == 'A' || in == 'a') { cin >> inm; wh = inm; }
            else if (in == 'B' || in == 'b')
            {
                cout << "1.8.1 - Code cleanup, cross-platform" << endl;
                cout << "1.8.0 - Open source" << endl;
                cout << "1.7.0 - Multi-language, save system" << endl;
            }
            else if (in == 'C' || in == 'c')
            {
                cout << "Mining Simulator by XINGJI Interactive Software" << endl;
                sleep_ms(1000);
            }
            else if (in == 'D' || in == 'd')
            {
                cout << "Language is now English-only in this build." << endl;
            }
            else if (in == 'E' || in == 'e')
            {
                cout << "Loan amount (interest 1%/day): ";
                cin >> inm;
                um += inm;
                rmb += inm;
            }
            else if (in == 'F' || in == 'f')
            {
                cout << "Current version: 1.8.1" << endl;
            }
            c = 0;
        }

        while (c == 1)
        {
            srand((int)time(0));
            l = rand() % 500 + 1;
            bd = d;
            w++;
            next_day(y, m, d);
            i++;
            if (bd != d && um > 0)
                um += um / 100;

            if (i % l == 0)
            {
                s++;
                cout << " #### " << y << "/" << m << "/" << d
                     << " | Match OK | success " << s << " fail " << n << " ####" << endl;
                sleep_ms(t);
            }
            else
            {
                n++;
                cout << " **** " << y << "/" << m << "/" << d
                     << " | Match FAIL | success " << s << " fail " << n << " ****" << endl;
                sleep_ms(t);
            }

            if (w == wh)
            {
                rmb = (long long)s * b_yuan;
                cout << "Total: " << s << " BTC = " << rmb << " RMB | Debt: " << um << " RMB" << endl;
                cout << " A.Continue   B.Menu   C.Repay debt" << endl;
                cin >> in;
                if (in == 'A' || in == 'a') { c = 1; }
                else if (in == 'B' || in == 'b') { c = 0; }
                else if (in == 'C' || in == 'c')
                {
                    if (rmb >= um) { rmb -= um; um = 0; cout << "Debt repaid. Balance: " << rmb << endl; }
                    else cout << "Insufficient balance." << endl;
                    sleep_ms(1000);
                    c = 0;
                }
                w = 0;
            }
        }
    }
}
