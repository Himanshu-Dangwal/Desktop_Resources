#include <bits/stdc++.h>
using namespace std;

void printSubsetsHelper(int idx, vector<int> &arr, string ans, int curr_sum, int target)
{

    if (idx == arr.size())
    {
        if (curr_sum == target)
        {
            cout << ans << endl;
        }
        return;
    }

    printSubsetsHelper(idx + 1, arr, ans + to_string(arr[idx]) + " ", curr_sum + arr[idx], target);
    printSubsetsHelper(idx + 1, arr, ans, curr_sum, target);
}

void printSubsets(vector<int> &arr, int target)
{
    string ans = "";
    printSubsetsHelper(0, arr, ans, 0, target);
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; cin >> arr[i++])
        ;
    int target;
    cin >> target;
    printSubsets(arr, target);
}