#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int count(vector<int> &arr, ll val)
{

    ll currSum = 0;
    int booksAllocated = 1;
    for (int i = 0; i < arr.size(); i++)
    {

        currSum += arr[i];

        if (currSum > val)
        {
            booksAllocated++;
            currSum = arr[i];
        }
    }

    return booksAllocated;
}

int findPages(vector<int> &arr, int n, int m)
{
    // Write your code here.

    int maxi_val = arr[0];

    for (int i = 1; i < n; i++)
    {
        maxi_val = max(maxi_val, arr[i]);
    }

    if (m == n)
    {
        return maxi_val;
    }

    if (m > n)
    {
        return -1;
    }

    int sum = 0;

    for (auto it : arr)
        sum += it;

    int low = maxi_val;
    int high = sum;

    while (low <= high)
    {
        ll mid = (low + (high - low) / 2);
        int counter = count(arr, mid);

        if (counter <= m)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; cin >> arr[i++])
        ;

    int m;
    cin >> m;

    cout << findPages(arr, n, m);
}