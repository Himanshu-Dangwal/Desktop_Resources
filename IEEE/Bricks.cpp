// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// void arrange_bricks(int N, long long x, vector<long long>& A) {
//     // Step 1: Sort the bricks
//     sort(A.begin(), A.end());

//     // Step 2: Initialize stacks
//     vector<vector<long long>> stacks;

//     // Step 3: Process each brick
//     for (const auto& brick : A) {
//         bool placed = false;

//         // Try to place the brick in an existing stack
//         for (auto& stack : stacks) {
//             if (stack.back() + x <= brick) {  // Can place on this stack
//                 stack.push_back(brick);
//                 placed = true;
//                 break;
//             }
//         }

//         // If not placed in any stack, create a new stack
//         if (!placed) {
//             stacks.push_back({ brick });
//         }
//     }

//     // Step 4: Output the number of stacks and their contents
//     cout << stacks.size() << endl;
//     for (const auto& stack : stacks) {
//         cout << stack.size() << " ";
//         // Print the size of the stack and the bricks from largest to smallest
//         for (auto it = stack.rbegin(); it != stack.rend(); ++it) {
//             cout << *it << " ";
//         }
//         cout << endl;
//     }
// }

// int main() {
//     // Standard Input
//     int N;
//     long long x;
//     cin >> N >> x;

//     vector<long long> A(N);
//     for (int i = 0; i < N; ++i) {
//         cin >> A[i];
//     }

//     // Call the function
//     arrange_bricks(N, x, A);

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

void arrange_bricks(int N, long long x, vector<long long>& A) {
    // Sort the bricks
    sort(A.begin(), A.end());

    // Min-heap to keep track of the top brick of each stack
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> minHeap;

    // Vector to store the stacks
    vector<vector<long long>> stacks;

    // Process each brick
    for (const auto& brick : A) {
        // If the heap is not empty and the smallest top brick can accommodate the current brick
        if (!minHeap.empty() && minHeap.top().first + x <= brick) {
            // Get the top of the stack
            auto [topBrick, index] = minHeap.top();
            minHeap.pop();

            // Place the current brick on this stack
            stacks[index].push_back(brick);
            // Update the new top of this stack in the min-heap
            minHeap.push({ brick, index });
        }
        else {
            // Create a new stack with the current brick
            stacks.push_back({ brick });
            minHeap.push({ brick, stacks.size() - 1 }); // Index of the new stack
        }
    }

    // Output the number of stacks and their contents
    cout << stacks.size() << endl;
    for (const auto& stack : stacks) {
        cout << stack.size() << " ";
        // Print from largest to smallest
        for (auto it = stack.rbegin(); it != stack.rend(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
}

int main() {
    // Input
    int N;
    long long x;
    cin >> N >> x;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Arrange the bricks into stacks
    arrange_bricks(N, x, A);

    return 0;
}
