// C++ program to print matrix in snake order
#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    // Traverse through all rows
    for (int i = 0; i < n; i++)
    {

        // If current row is even, print from
        // left to right
        if (i % 2 == 0)
        {
            for (int j = 0; j < m; j++)
                cout << mat[i][j] << " ";

            // If current row is odd, print from
            // right to left
        }
        else
        {
            for (int j = m - 1; j >= 0; j--)
                cout << mat[i][j] << " ";
        }
    }
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
    print(mat);
    return 0;
}
