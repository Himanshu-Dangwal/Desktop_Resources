#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main()
{
    string s;
    cin >> s;

    int i = 0;

    int n = s.length();
    int ans = 0;
    while (i < n)
    {
        int j = i;
        while (j < n && (s[j] == s[i]))
        {
            j++;
        }
        int pAns = j - i;
        i = j;
        ans = max(ans, pAns);
    }

    cout << ans;

    return 0;
}