#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    cout << n << " " << m << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == n - 1 && j == m - 1)
            {
                cout << "2"
                     << " ";
            }
            else
            {
                cout << "1"
                     << " ";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < m; i++)
    {
        if (i == m - 1)
        {
            cout << "2"
                 << " ";
        }
        else
        {
            cout << "1"
                 << " ";
        }
    }
    return 0;
}
