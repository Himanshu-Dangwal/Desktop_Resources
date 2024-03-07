#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;

    cout << q << endl;
    srand(time(0));
    int l = 1, r = 1000000;
    for (int i = 0; i < q; i++)
    {
        l = rand() % 100;
        if (l == 0)
            l++;

        while (true)
        {
            r = rand() % 1000000;
            if (r > l)
                break;
        }

        cout << l << " " << r << endl;
    }
    return 0;
}