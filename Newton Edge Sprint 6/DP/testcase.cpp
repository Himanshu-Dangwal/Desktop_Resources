#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << n << endl;
    n *= 2;

    for (int i = 0; i < n; i++)
    {
        int x = rand() % 50;
        x -= 10;
        cout << x << " ";
    }
}