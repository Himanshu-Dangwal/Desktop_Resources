#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int i;
    for (i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'U')
        {
            break;
        }
    }
    string ans = "";
    if (i == s.length())
    {
        cout << s << "ly";
        return 0;
    }
    else
    {
        ans = s.substr(i);
        ans += s.substr(0, i);
        ans += "ly";
    }

    cout << ans;
    return 0;
}