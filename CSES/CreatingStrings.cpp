#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

vector<int> fact(10, 1);

void printPermutations(string s, set<string> &st, string ans)
{

    if (s.length() == 0)
    {
        if (st.find(ans) == st.end())
        {
            st.insert(ans);
        }

        return;
    }

    for (int i = 0; i < s.length(); i++)
    {
        char curr = s[i];
        string remaining = s.substr(0, i) + s.substr(i + 1);
        printPermutations(remaining, st, curr + ans);
    }
}

int main()
{
    string s;
    cin >> s;

    for (int i = 1; i < 10; i++)
    {
        fact[i] = i * fact[i - 1];
    }

    vector<int> freq(26, 0);
    for (auto ch : s)
        freq[ch - 'a']++;

    int ans = fact[s.length()];
    for (int x : freq)
    {
        if (x > 0)
        {
            ans /= fact[x];
        }
    }
    cout << ans << endl;
    set<string> st;
    string sol = "";
    printPermutations(s, st, sol);
    for (auto str : st)
    {
        cout << str << endl;
    }
    return 0;
}