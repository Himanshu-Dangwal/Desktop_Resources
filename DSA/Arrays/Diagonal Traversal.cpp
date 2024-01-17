#include <bits/stdc++.h>
using namespace std;

void diagonalTraversal(vector<vector<int>> &arr)
{
    int n = arr.size();

    vector<vector<int>> ans;

    for (int g = 0; g < n + n - 1; g++)
    {
        vector<int> temp;
        int colNo = g < n ? g : n - 1;
        int rowNo = g < n ? 0 : g - n + 1;

        while (colNo >= 0 && rowNo < n)
        {
            temp.push_back(arr[rowNo][colNo]);
            rowNo++;
            colNo--;
        }

        ans.push_back(temp);
    }

    for (int i = 2; i < ans.size(); i += 2)
    {
        auto curr = ans[i];
        reverse(curr.begin(), curr.end());
        ans[i] = curr;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        for (auto it : ans[i])
        {
            cout << it << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    diagonalTraversal(arr);
}