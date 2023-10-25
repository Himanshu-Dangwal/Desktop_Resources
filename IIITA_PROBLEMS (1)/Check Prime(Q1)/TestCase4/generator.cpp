#include "testlib.h"
#include <bits/stdc++.h>
#define ll __int128
using namespace std;
#define nl '\n'
int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    string x;
    cin >> x;
    ofstream out("TestCase" + x + "/input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Strings = 1000;
    out << Strings << nl;
    for (int i = 0; i < 1000; i++)
    {
        out << rnd.next("[1-9][0-9]{99}") << nl;
    }
    out.close();
}