#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
int steps = 0;
vector<pair<int, int>> ans;
void toh(int n, int a, int b, int c)
{

    if (n == 0)
        return;

    toh(n - 1, a, c, b);
    ans.push_back({a, c});
    toh(n - 1, b, a, c);
}

int main()
{
    int n;
    cin >> n;

    toh(n, 1, 2, 3);
    cout << ans.size() << endl;
    for (auto entry : ans)
    {
        cout << entry.first << " " << entry.second << endl;
    }
    return 0;
}