#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int mini = INT_MAX;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] - arr[i] < mini)
            mini = arr[i + 1] - arr[i];
    }

    vector<vector<int>> ans;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] - arr[i] == mini)
        {
            vector<int> temp;
            temp.push_back(arr[i]);
            temp.push_back(arr[i + 1]);
            ans.push_back(temp);
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; cin >> arr[i++])
        ;

    vector<vector<int>> ans = minimumAbsDifference(arr);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}