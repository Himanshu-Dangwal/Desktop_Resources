#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

vector<int> getZArray(string s)
{
    int n = s.length();
    vector<int> z(n, 0);

    int l = 0, r = 0, i = 1;

    while (i < n)
    {
        if (i > r)
        {
            l = r = i;

            while (r < n && (s[r - l] == s[r]))
            {
                r++;
            }
            z[i] = r - l;
            r--;
        }
        else
        {
            int k = i - l;
            if (z[k] + i <= r)
            {
                z[i] = z[k];
            }
            else
            {
                l = i;
                while (r < n && (z[r - l] == z[r]))
                {
                    r++;
                }
                z[i] = r - l;
                r--;
            }
        }
        i++;
    }

    return z;
}

void solve()
{
    string pattern, text;
    cin >> pattern >> text;
    string s = pattern + "$" + text;
    vector<int> z = getZArray(s);

    for (int i = 0; i < z.size(); i++)
    {
        cout << z[i] << " ";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}