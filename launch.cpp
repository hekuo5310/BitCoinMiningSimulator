#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main()
{
	cout << "=Disclaimer=" << endl;
	cout << "Mining Simulator is developed by XINGJI Interactive Software. All rights reserved." << endl;
	cout << "Official site: https://www.xingjisoft.top/" << endl;

	this_thread::sleep_for(chrono::milliseconds(3000));

	// Run main game (compiled separately as bcms)
#ifdef _WIN32
	system("bcms_files\\bcms.exe");
#else
	system("bcms_files/bcms");
#endif

	return 0;
}
