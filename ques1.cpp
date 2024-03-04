#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int max_sum_without_common_elements(vector<int> &arr)
{
    // Step 1: Sort the array in descending order
    sort(arr.begin(), arr.end(), greater<int>());

    // Step 2: Initialize sets to keep track of included elements
    unordered_set<int> set1;
    unordered_set<int> set2;

    // Step 3: Iterate through the sorted array
    for (int num : arr)
    {
        // Add the current element to set1 if it doesn't have common elements with set2
        if (all_of(set1.begin(), set1.end(), [&](int num1)
                   { return set2.find(num1) == set2.end(); }))
        {
            set1.insert(num);
        }
        // Add the current element to set2 if it doesn't have common elements with set1
        else if (all_of(set2.begin(), set2.end(), [&](int num2)
                        { return set1.find(num2) == set1.end(); }))
        {
            set2.insert(num);
        }
    }

    // Step 4: Calculate the sum of elements in set1 and set2
    int max_sum = 0;
    for (int num : set1)
    {
        max_sum += num;
    }
    for (int num : set2)
    {
        max_sum += num;
    }

    return max_sum;
}

int main()
{
    // Example usage
    vector<int> arr = {15, 0, 105};
    int result = max_sum_without_common_elements(arr);

    cout << "Largest possible sum: " << result << endl;

    return 0;
}
