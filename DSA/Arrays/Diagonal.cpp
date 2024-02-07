#include <bits/stdc++.h>
using namespace std;

bool diagonalBinarySearch(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int low = 0, high = n * n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int midVal = matrix[mid / n][mid % n];

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
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int target;
    cin >> target;

    if (diagonalBinarySearch(matrix, target))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}
