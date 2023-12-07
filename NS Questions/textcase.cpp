#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    cout << n << endl;

    for (int i = 0; i < n; i++)
    {
        int val = rand() % 50;
        val++;
        cout << val << " ";
    }
    return 0;
}