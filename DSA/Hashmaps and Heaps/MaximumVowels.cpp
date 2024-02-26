#include <bits/stdc++.h>
using namespace std;

int maxVowels(string s, int k)
{
    int ans = 0;

    int cnt = 0;
    int i, j;
    j = 0;
    int n = s.length();
    for (i = 0; i < k; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            cnt++;
        }
    }

    for (i = k; i < n; i++)
    {
        ans = max(ans, cnt);
        if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
        {
            cnt--;
        }
        j++;
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            cnt++;
        }
    }

    ans = max(ans, cnt);

    return ans;
}

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;

    cout << maxVowels(s, k);
}