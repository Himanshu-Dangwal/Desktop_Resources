#include <bits/stdc++.h>
#define int long long
using namespace std;

int ans;
int a[100001], b[100001], hashh[100001];
vector<int> v[100001];
void fun(int node, int depth, int min_prefix, int cur_prefix, int k)
{

    cur_prefix += a[node];
    if (depth >= k)
    {
        ans = max(ans, cur_prefix - hashh[depth - k]);
    }
    min_prefix = min(min_prefix, cur_prefix);
    hashh[depth] = min_prefix;
    for (auto &it : v[node])
    {
        fun(it, depth + 1, min_prefix, cur_prefix, k);
    }
}
int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 1; i < n; i++)
    {

        v[b[i]].push_back(i);
    }
    fun(0, 1, 0, 0, k);
    cout << ans;
    return 0;
}
// code contributed by pratham bhatia
/*
16 4
24 32 16 14 -1 4 5 41 15 -31 2 11 12 11 10 -30
-1 0 1 2 1 4 5 4 7 8 9 10 0 12 13 14
*/