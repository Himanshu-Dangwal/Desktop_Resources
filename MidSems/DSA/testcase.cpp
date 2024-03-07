#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    cout << n << " " << m << endl;
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int val = rand() % 100;
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}