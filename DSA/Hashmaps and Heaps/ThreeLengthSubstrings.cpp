#include <bits/stdc++.h>
using namespace std;

int countGoodSubstrings(string s)
{
    int n = s.length();

    if (n < 3)
        return 0;
    unordered_map<char, int> mp;
    for (int i = 0; i < 3; i++)
    {
        mp[s[i]]++;
    }

    int ans = 0;
    if (mp.size() == 3)
        ans++;
    int j = 0;
    for (int i = 3; i < n; i++)
    {
        mp[s[j]]--;
        if (mp[s[j]] == 0)
            mp.erase(s[j]);
        mp[s[i]]++;

        if (mp.size() == 3)
        {
            ans++;
        }
        j++;
    }

    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << countGoodSubstrings(s);
}