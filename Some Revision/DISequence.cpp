#include <bits/stdc++.h>
using namespace std;

void DISequence(int n)
{
    if (n == 0)
        return;

    cout << n << " ";
    DISequence(n - 1);
    cout << n << " ";
}

int main()
{
    int n;
    cin >> n;
    DISequence(n);
}