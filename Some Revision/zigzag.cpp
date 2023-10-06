#include <bits/stdc++.h>
using namespace std;

void printPattern(int n)
{
    if (n == 0)
        return;

    cout << n << " ";
    printPattern(n - 1);
    cout << n << " ";
    printPattern(n - 1);
    cout << n << " ";
}

int main()
{
    int n;
    cin >> n;
    printPattern(n);
}