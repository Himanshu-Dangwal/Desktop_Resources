#include <bits/stdc++.h>
using namespace std;

int binarySearchInfinite(vector<int> &arr, int target)
{
    int low = 0, high = 1;

    // Find the range where the target may be present
    while (arr[high] < target)
    {
        low = high;
        high *= 2;
    }

    // Perform binary search within the identified range
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // Target not found
}

int main()
{
    string line;
    vector<int> b;
    getline(cin, line);
    istringstream iss(line);

    int n;
    while (iss >> n)
        b.push_back(n);

    int target;
    cin >> target;
    int result = binarySearchInfinite(b, target);

    if (result != -1)
        cout << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
