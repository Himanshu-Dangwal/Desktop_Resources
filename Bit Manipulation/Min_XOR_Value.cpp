#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; cin >> arr[i++])
        ;

    sort(arr.begin(), arr.end());

    int mini = INT_MAX;

    for (int i = 0; i < n - 1; i++)
    {
        mini = min(mini, arr[i] ^ arr[i + 1]);
    }

    cout << mini;
}