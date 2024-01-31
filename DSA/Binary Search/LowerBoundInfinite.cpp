#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &arr, int k)
{
    // If assuming infinite sorted array it is not possible to have a check on index out of bounds so unable to test the last element as a potential target element
    int n = arr.size();
    int low = 0, high = n - 1;

    int ans = high;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= k)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (ans == n)
    {
        return -1;
    }

    if (ans < n && arr[ans] != k)
    {
        return -1;
    }
    return ans;
}

int main()
{
    vector<int> arr;

    string line;
    getline(cin, line);
    istringstream ss(line);

    int x;
    while (ss >> x)
        arr.push_back(x);

    int k;
    cin >> k;
    cout << lowerBound(arr, k);
    return 0;
}
