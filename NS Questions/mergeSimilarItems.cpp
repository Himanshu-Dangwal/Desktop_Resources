#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2)
{
    vector<vector<int>> ans;

    map<int, int> mp;

    for (auto it : items1)
    {
        mp[it[0]] += it[1];
    }

    for (auto it : items2)
    {
        mp[it[0]] += it[1];
    }

    for (auto it : mp)
    {
        ans.push_back({it.first, it.second});
    }

    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> items1, items2;

    for (int i = 0; i < n + m; i++)
    {
        int val, weight;
        cin >> val >> weight;

        if (i < n)
            items1.push_back({val, weight});
        else
            items2.push_back({val, weight});
    }

    vector<vector<int>> ans = mergeSimilarItems(items1, items2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
}