#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> &arr, int index, vector<int> &ans, int k)
{
    if (index == arr.size() || ans.size() == k)
    {
        if (ans.size() == k)
        {
            for (int x : ans)
            {
                cout << x << " ";
            }
            cout << endl;
        }
        return;
    }
    ans.push_back(arr[index]);
    helper(arr, index + 1, ans, k);
    ans.pop_back();
    helper(arr, index + 1, ans, k);
    return;
}

void findCombinations(vector<int> &arr, int k)
{
    vector<int> ans;

    helper(arr, 0, ans, k);
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; cin >> arr[i++])
        ;

    int k;
    cin >> k;

    findCombinations(arr, k);
}