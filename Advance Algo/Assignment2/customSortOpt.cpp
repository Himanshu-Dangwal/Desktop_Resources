#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
#define PII pair<int, int>
typedef long long ll;

// Global priority queue to store elements and an unordered map to track their indices
priority_queue<int> pq;
unordered_map<int, int> mp; // Map to keep track of element to index mapping

// Function to extract the largest and second-largest elements and update their indices
int fun(int low, int high, vector<int> &arr)
{
    // Extract the largest element
    int maxi = pq.top();
    pq.pop();
    // Extract the second-largest element
    int secondMaxi = pq.top();
    pq.pop();

    // Retrieve the indices of the largest and second-largest elements
    int maxiIndex = mp[maxi];
    pq.push(maxi); // Push the largest element back to the priority queue

    // Update the index of the arr element present at high
    // We need to update the index of arr[high] because arr[high] will be getting swapped with arr[secondMaxiIndex]
    // The new index for arr[high] would be secondMaxiIndex
    int secondMaxiIndex = mp[secondMaxi];
    mp[arr[high]] = secondMaxiIndex; // Update the index in the map

    // Return the index of the second-largest element
    return secondMaxiIndex;
}

/* Custom sorting function */
void customSort(vector<int> &arr)
{
    int n = arr.size();        // Size of the array
    int low = 0, high = n - 1; // Initialize low and high for boundary

    // Phase 1: Sort the array except the first element
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

    // Input the elements of the array and initialize the priority queue and map
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        pq.push(arr[i]); // Push each element into the priority queue
        mp[arr[i]] = i;  // Update the index of each element in the map
    }

    // If the array has more than 1 element, apply the custom sorting
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
