#include <bits/stdc++.h>
using namespace std;

int binarySearchAlphabets(const vector<char> &alphabets, char target)
{
    int low = 0, high = alphabets.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (alphabets[mid] == target)
            return mid;
        else if (alphabets[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // Target not found
}

int main()
{

    vector<char> arr;
    string line;
    getline(cin, line);

    istringstream s(line);
    char ch;
    while (s >> ch)
    {
        arr.push_back(ch);
    }

    cin >> ch;
    int result = binarySearchAlphabets(arr, ch);
    cout << result;
    return 0;
}
