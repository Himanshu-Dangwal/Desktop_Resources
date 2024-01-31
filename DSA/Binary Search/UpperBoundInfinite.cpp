#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int k)
{
    int n = arr.size();

    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > k)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (arr[ans - 1] == k)
    {
        return ans - 1;
    }

    return -1;
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
    cout << upperBound(arr, k);
    return 0;
}
