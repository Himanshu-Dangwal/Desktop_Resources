#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    cout << n << endl;

    for (int i = 0; i < n; i++)
    {
        int x = rand() % 10;
        cout << x << " ";
    }
}