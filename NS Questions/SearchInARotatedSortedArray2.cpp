// #include <bits/stdc++.h>
// using namespace std;

// // returns true if we can reduce the search space in current binary search space
// bool isBinarySearchHelpful(vector<int> &nums, int start, int element)
// {
//     return nums[start] != element;
// }

// // returns true if element exists in first array, false if it exists in second
// bool existsInFirst(vector<int> &nums, int start, int element)
// {
//     return nums[start] <= element;
// }

// bool checkTarget(vector<int> &nums, int target)
// {
//     int n = nums.size();
//     if (n == 0)
//         return false;
//     int end = n - 1;
//     int start = 0;

//     while (start <= end)
//     {
//         int mid = start + (end - start) / 2;

//         if (nums[mid] == target)
//         {
//             return true;
//         }

//         if (!isBinarySearchHelpful(nums, start, nums[mid]))
//         {
//             start++;
//             continue;
//         }

//         bool pivotArray = existsInFirst(nums, start, nums[mid]);

//         bool targetArray = existsInFirst(nums, start, target);
//         if (pivotArray ^ targetArray)
//         {
//             if (pivotArray)
//             {
//                 start = mid + 1;
//             }
//             else
//             {
//                 end = mid - 1;
//             }
//         }
//         else
//         {
//             if (nums[mid] < target)
//             {
//                 start = mid + 1;
//             }
//             else
//             {
//                 end = mid - 1;
//             }
//         }
//     }
//     return false;
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> arr(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     int target;
//     cin >> target;

//     int index = rand() % n;
//     vector<int> temp;

//     for (int i = index + 1; i < n; i++)
//     {
//         temp.push_back(arr[i]);
//     }

//     for (int i = 0; i < index; i++)
//     {
//         temp.push_back(arr[i]);
//     }

//     for (int i = 0; i < temp.size(); i++)
//     {
//         arr[i] = temp[i];
//     }

//     if (checkTarget(arr, target))
//     {
//         cout << "true";
//     }
//     else
//     {
//         cout << "false";
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 200;

    for (int i = n - 1; i >= 0; i--)
    {

        for (int j = 0; j < n; j++)
        {
            if (j <= i)
            {
                cout << "1"
                     << " ";
            }
            else
            {
                cout << "0"
                     << " ";
            }
        }
        cout << endl;
    }
}
