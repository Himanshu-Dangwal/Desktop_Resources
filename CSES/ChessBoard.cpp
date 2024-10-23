#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
int cnt = 0;

bool isValid(int row, int col, vector<vector<char>> &arr)
{

    // In col
    for (int i = 0; i < row; i++)
    {
        if (arr[i][col] == 'q')
            return false;
    }

    // left diagonal

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (arr[i][j] == 'q')
            return false;
    }

    // right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < 8; i--, j++)
    {
        if (arr[i][j] == 'q')
            return false;
    }

    return true;
}

void placeQueens(int row, vector<vector<char>> &arr)
{
    if (row == 8)
    {
        cnt++;
        return;
    }

    for (int col = 0; col < 8; col++)
    {
        if (arr[row][col] != '*' && isValid(row, col, arr))
        {
            arr[row][col] = 'q';
            placeQueens(row + 1, arr);
            arr[row][col] = '.';
        }
    }
}

int main()
{
    vector<vector<char>> arr(8, vector<char>(8));

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> arr[i][j];
        }
    }

    placeQueens(0, arr);
    cout << cnt;
    return 0;
}