#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    bool anySwap = false;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                anySwap = true;
                swap(arr[j], arr[j + 1]);
            }
        }

        if (!anySwap)
        {
            break;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; cin >> arr[i++])
        ;
    bubbleSort(arr);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}