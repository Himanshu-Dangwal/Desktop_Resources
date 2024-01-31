#include <bits/stdc++.h>
using namespace std;

bool searchInRotated2DArray(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int low = 0, high = rows * cols - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int midVal = matrix[mid / cols][mid % cols];

        if (midVal == target)
        {
            return true;
        }
        else if (midVal < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return false;
}

int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int target;
    cin >> target;

    if (searchInRotated2DArray(matrix, target))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
