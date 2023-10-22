#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; cin >> arr[i++])
        ;

    int inc = arr[0];
    int exc = 0;

    for (int i = 1; i < n; i++)
    {
        int ninc = exc + arr[i];
        int nexc = max(inc, exc);

        inc = ninc;
        exc = nexc;
    }

    cout << max(inc, exc);
}
