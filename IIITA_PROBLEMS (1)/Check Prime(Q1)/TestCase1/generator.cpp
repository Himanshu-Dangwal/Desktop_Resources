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
    int Strings = 1;
    out << Strings << nl;
    out << rnd.next(1, 9);
    for (int i = 0; i + 1 < 100000; i++)
        out << rnd.next(0, 9);
    out << nl;
    out.close();
}