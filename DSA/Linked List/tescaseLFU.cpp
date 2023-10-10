#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    cout << n << endl;
    int capacity;
    capacity = rand() % 10;
    cout << capacity << endl;

    for (int i = 1; i < n; i++)
    {
        int option;
        option = rand() % 2;
        cout << option << endl;

        if (option == 0)
        {
            int val;
            val = rand() % 6;
            cout << val << endl;
        }
        else
        {
            int val1, val2;
            val1 = rand() % 15;
            val2 = rand() % 25;
            cout << val1 << " " << val2 << endl;
        }
    }
}