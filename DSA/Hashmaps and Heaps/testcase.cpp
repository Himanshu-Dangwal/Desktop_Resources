#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        int x = rand() % 26;
        char ch = 97 + x;
        cout << ch;
    }

    int k;
    k = rand() % n;
    cout << endl;
    cout << k;
}