#include <bits/stdc++.h>
using namespace std;

void swap_using_xor(int *n, int *m)
{
    *n = *n ^ *m;
    *m = *n ^ *m;
    *n = *n ^ *m;
    return;
}

int main()
{
    int n, m;
    cin >> n >> m;

    // n = n^m
    // m = n^m => n^m^m => n
    // n = n^m => (n^m)^n => m

    swap_using_xor(&n, &m);
    cout << n << " " << m;
}