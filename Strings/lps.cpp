#include <bits/stdc++.h>
using namespace std;

vector<int> getLPS(string &s)
{
    int i = 1, j = 0, n = s.length();
    vector<int> lps(n, 0);
    lps[0] = 0;

    while (i < n)
    {
        if (s[i] == s[j])
        {
            lps[i] = j + 1;
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

int main()
{
    string s;
    cin >> s;

    vector<int> lps = getLPS(s);
    for (int i = 0; i < lps.size(); i++)
    {
        cout << lps[i] << " ";
    }

    return 0;
}