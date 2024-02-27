#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    cout << n << endl;
    srand(time(0));
    for (int i = 0; i < 2 * n; i++)
    {
        int x = rand() % 1000;
        cout << x << " ";
    }
    return 0;
}