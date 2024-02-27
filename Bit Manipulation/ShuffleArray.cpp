#include <bits/stdc++.h>
using namespace std;
void shuffle(vector<int> &nums, int n)
{

    int i = n - 1, j = 2 * n - 1;
    while (i >= 0)
    {
        nums[j] <<= 10;
        nums[j] = nums[j] | nums[i];
        i--;
        j--;
    }

    i = 0, j = n;
    while (j < 2 * n)
    {
        nums[i] = nums[j] & (1023);
        nums[i + 1] = nums[j] >> 10;
        i += 2;
        j++;
    }

    return;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> nums[i];
    }

    shuffle(nums, n);
    for (int i = 0; i < 2 * n; i++)
    {
        cout << nums[i] << " ";
    }
}