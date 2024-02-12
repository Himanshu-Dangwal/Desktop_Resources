#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    cout << n << endl;

    for (int i = n; i >= 1; i--)
    {
        int x = rand() % 100000;
        cout << x << " ";
    }
    return 0;
}