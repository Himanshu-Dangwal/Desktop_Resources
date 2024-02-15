#include <bits/stdc++.h>
using namespace std;

vector<int> getModifiedArray(int length, vector<vector<int>> &updates)
{
    vector<int> res, nums(length + 1, 0);
    for (int i = 0; i < updates.size(); ++i)
    {
        nums[updates[i][0]] += updates[i][2];
        nums[updates[i][1] + 1] -= updates[i][2];
    }
    int sum = 0;
    for (int i = 0; i < length; ++i)
    {
        sum += nums[i];
        res.push_back(sum);
    }
    return res;
}

int main()
{
    int length;
    cin >> length;

    int n;
    cin >> n;

    vector<vector<int>> updates(n, vector<int>(3));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> updates[i][j];
        }
    }

    vector<int> res = getModifiedArray(length, updates);

    for (auto it : res)
    {
        cout << it << " ";
    }
}