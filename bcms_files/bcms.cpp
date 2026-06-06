#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "save.h"
using namespace std;

static void sleep_ms(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

int main()
{
	int last_rmb = 0;
	int y = 2022;
	int m = 1;
	int d = 1;
	int i = 0;
	int n = 0;
	int s = 0;
	int t = 10000;
	int l = 72;
	int cel = 0;
	int bd = 0;
	int inm;
	int c = 0;
	int xkm = 1;
	int mod = 0;
	int b_yuan = 36000;
	int lx = 1;
	char in;
	long long w = 0;
	long long wh = 100;
	long long rmb = 0;
	long long um = 0;
	long long um_temp = 0;
	int mail[100] = {1,1,1};
	string xk = "GTX1060";
	cout << "=Disclaimer=" << endl;
	cout << "Mining Simulator is developed by XINGJI Interactive Software. All rights reserved." << endl;
	cout << "Official site: https://www.xingjisoft.top/" << endl;
	sleep_ms(3000);
	cout << "|        Loading               |";
	sleep_ms(5000);
	cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
	cout << "|         finish               |";
	sleep_ms(100);
	cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
	read(rmb,s,xkm,xk);
	if (cel == 0)
	{
		cout << "|==========Mining Simulator 1.8.0==========|" << endl;
		cout << "| P O W E R E D   B Y   X I N G J I        |" << endl;
		cout << "|         >>> loading <<<                   |" << endl;
		sleep_ms(1500);
	}
	else if (cel == 1)
	{
		cout << "|=========Mining Simulator 1.8.0==========|" << endl;
		cout << "|    P O W E R E D   B Y   X I N G J I    |" << endl;
		cout << "|             >>> loading <<<             |" << endl;
		sleep_ms(1500);
	}
	for (int i = 0; i < 40; i++)
	{
		cout << endl;
		sleep_ms(100);
	}
	in = 0;
	while (true)
	{
		last_rmb = rmb;
			if (cel == 0)
			{
				cout << "*********************************************" << endl;
				cout << "*                                           *" << endl;
				cout << "*    Mining Simulator 1.8.0 for XINGJI     *" << endl;
				cout << "*                                           *" << endl;
				cout << "*********************************************" << endl;
				cout << " A.Start   B.Exit   C.Settings   D.Shop   E.Mail " << endl;
			}
			else if (cel == 1)
			{
				cout << "*******************************************************" << endl;
				cout << "*                                                     *" << endl;
				cout << "*      Mining simulator 1.8.0 for XINGJI STUDIOS      *" << endl;
				cout << "*                                                     *" << endl;
				cout << "*******************************************************" << endl;
				cout << " A.Start game   B.Exit   C.Settings   D.Shop   E.Mail " << endl;
			}
			cin >> in;
			if (in == 'A' || in == 'a')
			{
				c = 1;
			}
			else if (in == 'B' || in == 'b')
			{
				cout << " | Thanks for playing Mining Simulator | " << endl;
				cout << " |          Saving and exit...         | " << endl;
				write(rmb,s,xkm,xk);
				sleep_ms(1000);
				return 0;
			}
			else if (in == 'C' || in == 'c')
			{
				c = 2;
			}
			else if (in == 'D' || in == 'd')
			{
				cout << "A.Draw (NEW)   B.Equipment maintenance" << endl;
				cin >> in;
				if (in == 'a' || in == 'A')
				{
					cout << "-Draw-" << endl;
					cout << ">>> 10000 RMB/time" << endl;
					cout << "A.Go!" << endl;
					cin >> in;
					if (in == 'a' || in == 'A')
					{
						int xkr = 0;
						srand((int)time(0));
						xkr = rand() % 10000;
						if (xkr == 1)
						{
							cout << "-Congratulations-" << endl;
							cout << "H100 SSSSS" << endl;
							xk = "H100";
							t = 0;
						}
						else if (xkr >= 10 && xkr <= 15)
						{
							cout << "-Congratulations-" << endl;
							cout << "Tesla H800 SSSS" << endl;
							xk = "H800";
							t = t - 9500;
						}
						else if (xkr >= 16 && xkr <= 20)
						{
							cout << "-Congratulations-" << endl;
							cout << "RTX5090 SSS" << endl;
							xk = "RTX5090";
							t = t - 9000;
						}
						else if (xkr >= 21 && xkr <= 25)
						{
							cout << "-Congratulations-" << endl;
							cout << "RTX5080 SSS" << endl;
							xk = "RTX5080";
							t = t - 8000;
						}
						else if (xkr >= 26 && xkr <= 30)
						{
							cout << "-Congratulations-" << endl;
							cout << "RTX4090 SSS" << endl;
							xk = "RTX4090";
							t = t - 8000;
						}
						else if (xkr >= 31 && xkr <= 40)
						{
							cout << "-Congratulations-" << endl;
							cout << "RTX4080 SS" << endl;
							xk = "RTX4080";
							t = t - 7300;
						}
						else if (xkr >= 41 && xkr <= 70)
						{
							cout << "-Congratulations-" << endl;
							cout << "RTX3090 SS" << endl;
							xk = "RTX3090";
							t = t - 7000;
						}
						else if (xkr >= 71 && xkr <= 140)
						{
							cout << "-Congratulations-" << endl;
							cout << "RTX3070 S" << endl;
							xk = "RTX3070";
							t = t - 6000;
						}
						else if (xkr >= 141 && xkr <= 240)
						{
							cout << "-Congratulations-" << endl;
							cout << "RTX2090 S" << endl;
							xk = "RTX2090";
							t = t - 6000;
						}
						else if (xkr >= 241 && xkr <= 1240)
						{
							cout << "-Congratulations-" << endl;
							cout << "RTX2070 A" << endl;
							xk = "RTX2070";
							t = t - 4500;
						}
						else if (xkr >= 1241 && xkr <= 2240)
						{
							cout << "-Congratulations-" << endl;
							cout << "RTX1090 A" << endl;
							xk = "RTX1090";
							t = t - 4500;
						}
						else if (xkr >= 2241 && xkr <= 4238)
						{
							cout << "-Congratulations-" << endl;
							cout << "RTX1070 B" << endl;
							xk = "RTX1070";
							t = t - 3000;
						}
						else if (xkr == 4239)
						{
							cout << "-Congratulations-" << endl;
							cout << "RX6000 SSS+" << endl;
							xk = "RX6000XT";
							t = t - 9900;
						}
						else if (xkr == 4240)
						{
							cout << "-Congratulations-" << endl;
							cout << "RX6000 SSS" << endl;
							xk = "RX6000";
							t = t - 9000;
						}
						else if (xkr >= 4241 && xkr <= 4340)
						{
							cout << "-Congratulations-" << endl;
							cout << "RX5000 SS" << endl;
							xk = "RX5000";
							t = t - 7500;
						}
						else if (xkr >= 4341 && xkr <= 4440)
						{
							cout << "-Congratulations-" << endl;
							cout << "RX4000 S" << endl;
							xk = "RX4000";
							t = t - 6000;
						}
						else if (xkr >= 4441 && xkr <= 9990)
						{
							cout << "-Congratulations-" << endl;
							cout << "Money*6666 Bitcoin*6" << endl;
						}
						else if (xkr >= 9991)
						{
							cout << "-Congratulations-" << endl;
							cout << "homo... SB grade" << endl;
							cout << "haha, you found a hidden easter egg!" << endl;
							cout << "A.Use it!  B.Restart game (lose all data)" << endl;
							cin >> in;
							if (in == 'b' || in == 'B')
							{
								cout << "-Game Over-" << endl;
								return 0;
							}
							else
							{
								cout << "OK, you chose to keep it!" << endl;
								sleep_ms(750);
							}
						}
						else
						{
							cout << "Nothing, sorry!" << endl;
						}
					}
				}
				if (t < 0) t = 0;
				if (l < 1) l = 1;
				if (rmb < 0 && rmb >= -10000)
				{
					cout << "Considering your difficulties, MXUSB provides free overdraft service (maximum overdraft limit -10000)" << endl;
					cout << "Have a nice day!" << endl << endl;
					cout << m << "/" << d << "/" << y << endl;
				}
				else if (rmb < -10000)
				{
					cout << "You have exceeded your free overdraft limit, interest will be calculated at %1/day." << endl;
					um = um + abs(rmb);
				}
				if (t < 0) t = 0;
			}
			if (in == 'E' || in == 'e')
			{
				cout << endl;
				if (mail[0] == 1)
				{
					cout << "New mail......" << endl;
					cout << "Welcome to Mining Simulator!" << endl;
					cout << "XINGJI thanks you for playing, we will upload saves to XINGJI cloud in the future and migrate to Mining Simulator 2." << endl;
					cout << "Enter A to claim reward: Money*100w" << endl;
					cout << endl;
					cin >> in;
					cout << "Claimed successfully!" << endl;
					rmb = rmb + 1000000;
					mail[0] = 0;
				}
			}
			if (rmb < 0 && rmb >= -10000)
			{
				cout << "Considering your difficulties, MXUSB provides free overdraft service (maximum overdraft limit -10000)" << endl;
				cout << "Have a nice day!" << endl << endl;
				cout << m << "/" << d << "/" << y << endl;
			}
			else if (rmb < -10000)
			{
				cout << "You have exceeded your free overdraft limit, interest will be calculated at %1/day." << endl;
				um = um + abs(rmb);
			}
			if (t < 0) t = 0;
		if (c == 2)
		{
			if (cel == 0)
			{
				in = 0;
				cout << "A.Auto-pause entries   B.Changelog   C.About   D.DLC import   E.Language   F.Loan   G.Mining mode   H.VIP   I.Key   J.Version check" << endl;
				cout << "A:" << wh << endl;
				cout << "Please select:";
			}
			else if (cel == 1)
			{
				in = 0;
				cout << "A.How many entries are automatically paused after   B.Changelog   C.About   D.DLC import   E.Language   F.Loan   G.Mining mode   H.VIP   I.Key   J.up" << endl;
				cout << "A:" << wh << endl;
				cout << "Please select the item you want to change:";
			}
			cin >> in;
			if (in == 'A' || in == 'a')
			{
				cin >> inm;
				wh = inm;
			}
			else if (in == 'B' || in == 'b')
			{
				cout << "================ XINGJI Update ================" << endl;
				cout << "1.8.0 - Open source" << endl;
				cout << "1.7.0Pro - Save feature" << endl;
				cout << "1.7.0 - Multi-language support" << endl;
				cout << "1.6.9 - Security update" << endl;
				cout << "1.6.8 - Illustrated book update" << endl;
				cout << "1.6.7 - Schema update" << endl;
				cout << "1.6.5 & 1.6.6 - Anniversary/National Day update" << endl;
				cout << "1.6.4 - Skills update" << endl;
				cout << "1.6.3 - Partition update" << endl;
				cout << "1.6.2 - Graphics cards update" << endl;
				cout << "1.6.1 - Init page update" << endl;
				cout << "1.6.0 - Save feature" << endl;
				cout << "1.5.x - Various updates" << endl;
			}
			else if (in == 'C' || in == 'c')
			{
				cout << "===================Mining Simulator===================" << endl;
				cout << "XINGJI Interactive Software" << endl;
				cout << "======================================================" << endl;
				cout << "Thanks for playing! Have a nice day!" << endl;
				sleep_ms(1000);
			}
			else if (in == 'D' || in == 'd')
			{
				cout << "DLC feature is only available on Windows." << endl;
			}
			else if (in == 'E' || in == 'e')
			{
				cout << "A.Chinese   B.English" << endl;
				cin >> in;
				if (in == 'A' || in == 'a')
				{
					cel = 0;
				}
				else if (in == 'B' || in == 'b')
				{
					cel = 1;
				}
			}
			else if (in == 'F' || in == 'f')
			{
				cout << "Please enter your loan amount (interest 1%/day):" << endl;
				cin >> inm;
				um = um + inm;
			}
			else if (in == 'G' || in == 'g')
			{
				cout << "Please select the mode   current mode Chiacoin mining" << endl;
				cout << "               A.Bitcoin   B.Chiacoin               " << endl;
				cin >> in;
				if (in == 'A' || in == 'a')
				{
					cout << "The switch was successful" << endl;
					mod = 0;
				}
				else if (in == 'B' || in == 'b')
				{
					cout << "The switch was successful" << endl;
					mod = 1;
				}
			}
			else if (in == 'H' || in == 'h')
			{
				cout << "XINGJI VIP   It only costs 1$" << endl;
			}
			else if (in == 'I' || in == 'i')
			{
				string m_on_key_word = "";
				cout << "Enter key: ";
				cin >> m_on_key_word;
				cout << endl;
				if (m_on_key_word == "167YYDSX2073")
				{
					cout << "Success!" << endl << "Money*11451 Bitcoin*4" << endl;
					rmb = rmb + 11451;
					s = s + 4;
				}
				else if (m_on_key_word == "376CZXCF7732")
				{
					cout << "Success!" << endl << "Money*8888 Bitcoin*8" << endl;
					rmb = rmb + 8888;
					s = s + 8;
				}
				else if (m_on_key_word == "789CZKCT8601")
				{
					cout << "Success!" << endl << "Money*6666 Bitcoin*6" << endl;
					rmb = rmb + 6;
					s = s + 6;
				}
			}
			else if (in == 'J' || in == 'j')
			{
				cout << "Checking for updates..." << endl;
				sleep_ms(1000);
				cout << "Current version: 1.8.0" << endl;
			}
		}
		while (c == 1)
		{
			srand((int)time(0));
			l = rand() % 500;
			bd = d;
			w++;
			if (m == 2)
			{
				int feb_max = (y % 4 == 0) ? 29 : 28;
				if (d == feb_max) { m++; d = 1; } else { d++; }
			}
			else if (m == 12)
			{
				if (d == 31) { y++; d = 1; m = 1; } else { d++; }
			}
			else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10)
			{
				if (d == 31) { m++; d = 1; } else { d++; }
			}
			else
			{
				if (d == 30) { m++; d = 1; } else { d++; }
			}
			i++;
			if (bd != d)
			{
				um = um + rmb / 100 * 0.5;
			}
			int x = 0;
			if (m < 10)
			{
				x++;
				if (d < 10) x++;
			}
			else if (d < 10)
			{
				x++;
			}
			if (i % l == 0)
			{
				s++;
				cout << " #### " << y << "/" << m << "/" << d;
				for (int i = 0; i < x; i++) cout << " ";
				cout << " | The match was successful | success " << s << " fail " << n << " #### " << endl;
				sleep_ms(t);
			}
			else
			{
				n++;
				cout << " **** " << y << "/" << m << "/" << d;
				for (int i = 0; i < x; i++) cout << " ";
				cout << " |      The match failed     | success " << s << " fail " << n << " **** " << endl;
				sleep_ms(t);
			}
			if (w == wh)
			{
				cout << "You now have a total of " << s << " Bitcoin worth " << s * b_yuan << "$" << endl;
				rmb = s * b_yuan;
				cout << "Current debt:" << um * 0.16 << "$" << endl;
				cout << "     A. Continue     B. Exit     C. Menu     D. Debt repayment" << endl;
				cin >> in;
				if (in == 'A' || in == 'a')
				{
					c = 1;
				}
				else if (in == 'B' || in == 'b')
				{
					cout << "Please use C to go to menu and save before exiting." << endl;
				}
				else if (in == 'C' || in == 'c')
				{
					c = 2;
				}
				else if (in == 'D' || in == 'd')
				{
					rmb = rmb - um;
					if (rmb < 0)
					{
						cout << "Sorry, insufficient balance to repay debt" << endl;
					}
					else
					{
						cout << "The debt was repaid" << endl;
						cout << "The current balance " << rmb * 0.16 << "$" << endl;
						um = 0;
					}
					sleep_ms(1000);
				}
				w = 0;
			}
		}
	}
}
