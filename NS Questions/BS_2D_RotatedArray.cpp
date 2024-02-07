#include <bits/stdc++.h>
using namespace std;

bool searchInRotated2DArray(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    int rowNo = -1;
    for (int i = 0; i < rows; i++)
    {
        if (matrix[i][0] <= target && matrix[i][cols - 1] >= target)
        {
            rowNo = i;
            int low = 0, high = cols - 1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;

                if (matrix[rowNo][mid] == target)
                {
                    return true;
                }

                if (matrix[rowNo][mid] < target)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
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
