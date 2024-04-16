//[C++]
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long l;
    long long r;
    cin >> l >> r;
    if (l % 2 == 0)
        l++;
    if (r % 2 == 0)
        r--;

    int no_of_odd_nos = ((r - l) / 2) + 1;
    if (no_of_odd_nos % 2)
    {
        cout << "odd\n";
    }
    else
        cout << "even\n";
}