#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    // Write your code here
    int n;
    cin >> n;
    vector<pair<int, int>> intervals;
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        intervals.push_back(make_pair(end, start));
    }
    sort(intervals.begin(), intervals.end());
    ll count = 1;
    int mi = intervals[0].first;
    for (int i = 1; i < n; i++)
    {
        if (intervals[i].second >= mi)
        {
            mi = intervals[i].first;
            count++;
        }
    }
    cout << count;
    return 0;
}