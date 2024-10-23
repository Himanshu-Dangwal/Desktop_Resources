#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main()
{
    string s;
    cin >> s;

    unordered_map<char, int> mp;
    for (auto ch : s)
        mp[ch]++;

    int cnt = 0;
    char ch;
    bool flag = false;
    for (auto it : mp)
    {
        if (it.second % 2)
            cnt++, flag = true, ch = it.first;
        ;
    }

    if (cnt > 1)
    {
        cout << "NO SOLUTION";
        return 0;
    }

    int n = s.length();
    int i = 0, j = n - 1;

    for (auto it : mp)
    {
        if (it.second % 2)
            continue;

        char curr = it.first;
        int freq = it.second;
        while (freq > 0)
        {
            s[i] = curr;
            s[j] = curr;
            i++;
            j--;
            freq -= 2;
        }
    }

    if (flag)
    {
        while (i <= j)
        {
            s[i] = s[j] = ch;
            i++;
            j--;
        }
    }

    cout << s;

    return 0;
}