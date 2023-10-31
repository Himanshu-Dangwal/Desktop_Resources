#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        int sz;
        cin >> sz;
        vector<int> arr(sz);
        for (int j = 0; j < sz; j++)
        {
            cin >> arr[j];
        }

        sort(arr.begin(), arr.end());
        cout << sz << " ";
        for (int x : arr)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}