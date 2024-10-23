#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

vector<string> solve(int n)
{
    if (n == 1)
    {
        return {"0", "1"};
    }

    vector<string> prevAns = solve(n - 1);
    vector<string> ans;

    for (auto str : prevAns)
    {
        ans.push_back("0" + str);
    }

    reverse(prevAns.begin(), prevAns.end());
    for (auto str : prevAns)
    {
        ans.push_back("1" + str);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> ans = solve(n);
    for (auto str : ans)
    {
        cout << str << endl;
    }
    return 0;
}