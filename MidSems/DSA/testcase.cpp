#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    cout << n << endl;
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        int val = rand() % 3;
        cout << val << " ";
    }
    return 0;
}