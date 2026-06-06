#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void save_game(long long rmb, long long bit_coin, long long xkm, const string& xk)
{
    ofstream fout("archive.txt");
    fout << rmb << "\n" << bit_coin << "\n" << xk << "\n" << xkm << "\n";
}

void load_game(long long& rmb, long long& bit_coin, long long& xkm, string& xk)
{
    ifstream fin("archive.txt");
    if (fin)
    {
        fin >> rmb >> bit_coin >> xk >> xkm;
    }
}
