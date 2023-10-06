#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    vector<int> arr;

    arr = {1, 2, 3, 4, 5};
    cout << arr.capacity() << endl;

    cout << "Upper Bound ::" << endl;
    int index = upper_bound(arr.begin(), arr.end(), 5) - arr.begin();
    cout << arr.capacity() << endl;

    cout << "Lower Bound ::" << endl;
    index = lower_bound(arr.begin(), arr.end(), 5) - arr.begin();
    cout << index;
}