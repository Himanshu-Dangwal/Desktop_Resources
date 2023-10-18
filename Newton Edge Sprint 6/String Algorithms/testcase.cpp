#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string text = "";
    for (int i = 0; i < n; i++)
    {
        int x = rand() % 26;
        char ch = 'a' + x;
        text += ch;
    }

    int m;
    cin >> m;

    string pattern = "";

    for (int i = 0; i < m / 2; i++)
    {
        int x = rand() % 26;
        char ch = 'a' + x;
        pattern += ch;
    }

    text += pattern;
    for (int i = 0; i < m / 2; i++)
    {
        int x = rand() % 26;
        char ch = 'a' + x;
        text += ch;
    }

    cout << text << endl
         << pattern;
}