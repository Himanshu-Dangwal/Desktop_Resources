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
    int value;
};

void insert(int val, TrieNode* head) {
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
    curr->value = val;
}

int query(int val, TrieNode* head) {
    TrieNode* curr = head;
    for (int i = 31;i >= 0;i--) {
        int b = (val >> i) & 1;
        if (b) {
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
        else {
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
    }

    return val ^ curr->value;
}

int findMaxXorSubarray(vector<int>& arr) {
    int maxi = INT_MIN;
    TrieNode* head = new TrieNode();
    int preXor = 0;
    insert(preXor, head);

    for (int i = 0;i < arr.size();i++) {
        preXor ^= arr[i];
        insert(preXor, head);
        maxi = max(maxi, query(preXor, head));
    }
    return maxi;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0;i < n;i++) cin >> arr[i];

    cout << findMaxXorSubarray(arr);
    return 0;
}