#include <bits/stdc++.h>
using namespace std;

int main()
{

    int q;
    cin >> q;

    cout << q << endl;
    srand(time(0));
    for (int i = 0; i < q; i++)
    {
        int x = rand() % 1000000;
        cout << x << endl;
    }

    return 0;
}