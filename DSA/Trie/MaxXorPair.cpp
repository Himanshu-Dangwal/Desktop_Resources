#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
// find_by_order() 
// order_of_key()
struct TrieNode {
    TrieNode* left, * right;
};

void insert(TrieNode* head, int val) {
    TrieNode* curr = head;
    for (int i = 31;i >= 0;i--) {
        int b = (val >> i) & 1;

        if (b) {
            if (curr->right) curr = curr->right;
            else {
                curr->right = new TrieNode();
                curr = curr->right;
            }
        }
        else {
            if (curr->left) curr = curr->left;
            else {
                curr->left = new TrieNode();
                curr = curr->left;
            }
        }

    }
}

int findMaxXorPair(vector<int>& arr, TrieNode* head) {
    int maxi = INT_MIN;

    for (int i = 0;i < arr.size();i++) {
        TrieNode* curr = head;
        int currAns = 0;
        int val = arr[i];
        for (int j = 31;j >= 0;j--) {
            int bit = (val >> j) & 1;
            if (bit) {
                if (curr->left) {
                    currAns += (int)pow(2, i);
                    curr = curr->left;
                }
                else {
                    curr = curr->right;
                }
            }
            else {
                if (curr->right) {
                    currAns += (int)pow(2, i);
                    curr = curr->right;
                }
                else {
                    curr = curr->left;
                }
            }
        }
        maxi = max(maxi, currAns);
    }

    return maxi;
}

int main()
{
    int n;
    cin >> n;
    TrieNode* head = new TrieNode();

    vector<int> arr(n);
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
        insert(head, arr[i]);
    }

    cout < findMaxXorPair(arr, head);

    return 0;
}