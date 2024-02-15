#include <bits/stdc++.h>
using namespace std;

int compareRow(vector<int> &a1, vector<int> &a2)
{
    int n = a1.size();
    for (int i = 0; i < n; i++)
    {
        if (a1[i] < a2[i])
            return 1;

        else if (a1[i] > a2[i])
            return -1;
    }

    return 0;
}

int binaryCheck(vector<vector<int>> &mat, vector<int> &arr)
{
    int m = mat.size();
    int l = 0, r = m - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int temp = compareRow(mat[mid], arr);
        if (temp == 0)
            return mid + 1;

        else if (temp == 1)
            l = mid + 1;

        else
            r = mid - 1;
    }

    // No valid row found
    return -1;
}

// Driver code
int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    vector<int> row(m);
    for (int i = 0; i < m; cin >> row[i++])
        ;

    cout << binaryCheck(mat, row);

    return 0;
}
