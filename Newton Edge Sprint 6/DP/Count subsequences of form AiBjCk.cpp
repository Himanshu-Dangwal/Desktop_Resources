#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int a = 0, ab = 0, abc = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a')
        {
            a = 2 * a + 1;
        }
        else if (s[i] == 'b')
        {
            ab = 2 * ab + a;
        }
        else
        {
            abc = 2 * abc + ab;
        }
    }

    cout << abc;
    return 0;
}