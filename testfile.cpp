
// Header Files
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dx[8] = {2, 1, 0, -1, -2, -1, 0, 1}; // For direct movements, we skip 1 cell (move 2 cells)
int dy[8] = {0, 1, 2, 1, 0, -1, -2, -1};

/*
 * matrix represents the elements in each cell of the matrix of size N*M.
 */
void funcHopSkipJump(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int i = 0, j = 0;
    int ans = matrix[i][j]; // Initial value
    visited[i][j] = true;   // Mark the start as visited
    int dir = 1;            // Start moving down initially (index 1 in dx/dy arrays)

    while (true)
    {
        bool moved = false;
        cout << i << " " << j << endl;
        // Try to move in the current direction and keep moving in anti-clockwise directions if blocked
        for (int d = 0; d < 8; d++)
        {
            // int newDir = (dir + d) % 8; // Rotate in anticlockwise direction
            int newI = i + dx[d];
            int newJ = j + dy[d];

            // Check if the new position is within bounds and unvisited
            if (newI >= 0 && newI < n && newJ >= 0 && newJ < m && !visited[newI][newJ])
            {
                i = newI;
                j = newJ;
                ans = matrix[i][j]; // Get the new value
                visited[i][j] = true;
                // dir = newDir; // Update the current direction
                moved = true;
                break;
            }
        }

        // If no move was possible, break out of the loop
        if (!moved)
            break;
    }

    cout << ans;
}

int main()
{
    // input for matrix
    int matrix_row;
    int matrix_col;
    cin >> matrix_row;
    cin >> matrix_col;

    vector<vector<int>> matrix;
    for (int idx = 0; idx < matrix_row; idx++)
    {
        vector<int> temp_vector;
        for (int jdx = 0; jdx < matrix_col; jdx++)
        {
            int temp;
            cin >> temp;
            temp_vector.push_back(temp);
        }
        matrix.push_back(temp_vector);
    }

    funcHopSkipJump(matrix);

    return 0;
}