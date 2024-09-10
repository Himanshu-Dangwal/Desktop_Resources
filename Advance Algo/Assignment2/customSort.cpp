#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

/* Function to find the index of the second-largest number in the range [low, high] in the array 'arr'
   Parameters:
   - low: the starting index of the range
   - high: the ending index of the range
   - arr: the array in which we are searching for the second-largest element

   The function iterates from 'low' to 'high', updating the largest and second-largest numbers it encounters.
   It returns the index of the second-largest number found in the range.
*/
int fun(int low, int high, vector<int> &arr)
{
    // Variables to store the largest (maxi) and second-largest (secondMaxi) values
    int maxi = INT_MIN, secondMaxi = INT_MIN;

    // Indices to store the positions of the largest and second-largest numbers
    int maxiIndex = -1, secondMaxiIndex = -1;

    // Traverse the array from 'low' to 'high'
    while (low <= high)
    {
        // If current element is greater than 'maxi', update both 'maxi' and 'secondMaxi'
        // 'secondMaxi' will get the value of 'maxi', and the current element becomes 'maxi'
        if (arr[low] > maxi)
        {
            secondMaxi = maxi; // The previous largest becomes the second-largest
            maxi = arr[low];   // Update 'maxi' with the current element

            // Update the corresponding indices
            secondMaxiIndex = maxiIndex;
            maxiIndex = low;
        }
        // If current element is greater than 'secondMaxi' but smaller than 'maxi', update 'secondMaxi'
        else if (arr[low] > secondMaxi)
        {
            secondMaxi = arr[low];
            secondMaxiIndex = low;
        }

        // Move to the next element
        low++;
    }

    // Return the index of the second-largest element
    return secondMaxiIndex;
}

/* Custom sorting function:
   - This function sorts an array in two phases:
     - Phase 1: Sort the array, leaving the largest element in the first position.
     - Phase 2: Shift the largest element (which is now at the first position) to the end, resulting in a fully sorted array.

   Steps:
   - Initialize 'low' = 0 and 'high' = n - 1 (the entire array as the initial boundary).
   - Use the 'fun' function to find the second-largest element in the current boundary [low, high].
   - Swap the second-largest element with the last element of the current boundary.
   - Reduce the boundary size by moving 'high' one position to the left.
   - Repeat the above steps until only one element remains unsorted (when low >= high).

   - After Phase 1, all elements except the first are sorted, and the largest element is at index 0.
   - In Phase 2, we shift the largest element towards the end of the array to fully sort it.
*/
void customSort(vector<int> &arr)
{
    int n = arr.size();        // Size of the array
    int low = 0, high = n - 1; // Initialize low and high for boundary

    // Phase 1: Sort the array except the first element (which will hold the largest value)
    while (low < high)
    {
        int index = fun(low, high, arr); // Find the second-largest element in the range [low, high]
        swap(arr[high], arr[index]);     // Swap it with the last element in the boundary
        high--;                          // Reduce the boundary by one
    }

    // Phase 2: Shift the largest element (which is now at index 0) towards the end
    int j = low + 1; // Start at index 1
    while (j < n)
    {
        swap(arr[low], arr[j]); // Swap the first element with each subsequent element
        low++;
        j++;
    }
}

int main()
{
    int n; // Number of elements in the array
    cin >> n;

    vector<int> arr(n); // Declare an array of size 'n'

    // Input the elements of the array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // If array has more than 1 element, apply the custom sorting
    if (n > 1)
    {
        customSort(arr);
    }

    // Output the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

/* Detailed Example:

Let's take an example where n = 4, and the elements of the array are:
arr = {4, 3, 9, 7}

Phase 1: Sorting the array except the first element:
- Initial array: [4, 3, 9, 7]
- Call 'fun' on the entire array [0, 3] and find the second-largest element (index 3, value 7).
- Swap arr[3] with arr[3] (no change).

- Call 'fun' on the range [0, 2], find the second-largest element (index 0, value 4).
- Swap arr[2] with arr[0], resulting in [9, 3, 4, 7].

- Call 'fun' on the range [0, 1], find the second-largest element (index 1, value 3).
- Swap arr[1] with arr[1] (no change).

After Phase 1, the array becomes: [9, 3, 4, 7]

Phase 2: Shifting the largest element (9) to the end:
- Swap arr[0] with arr[1], resulting in [3, 9, 4, 7].
- Swap arr[1] with arr[2], resulting in [3, 4, 9, 7].
- Swap arr[2] with arr[3], resulting in [3, 4, 7, 9].

Final sorted array: [3, 4, 7, 9]

*/
