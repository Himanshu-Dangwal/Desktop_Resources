#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
void dfs(string s, int open, int close)
{

    if (open == 0 && close == 0)
    {
        ans.push_back(s);
        return;
    }

    if (open > 0)
        dfs(s + "(", open - 1, close);
    if (close > open)
        dfs(s + ")", open, close - 1);
}

vector<string> generateParenthesis(int n)
{
    string s = "";
    dfs(s, n, n);

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<string> ans = generateParenthesis(n);

    for (auto it : ans)
    {
        cout << it << endl;
    }
}
