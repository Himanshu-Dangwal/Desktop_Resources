#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

ll find(pair<int, int> &a, pair<int, int> &b)
{
    int x1 = a.first;
    int y1 = a.second;
    int x2 = b.first;
    int y2 = b.second;

    ll dist = (((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
    return dist;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vp[i].first;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> vp[i].second;
    }
    ll maxi = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ll currDist = find(vp[i], vp[j]);
            maxi = max(maxi, currDist);
        }
    }
    cout << maxi;
    return 0;
}