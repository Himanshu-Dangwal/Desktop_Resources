#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool traverse(TreeNode *r, unordered_map<int, TreeNode *> &m, int min_left = INT_MIN, int max_right = INT_MAX)
{
    if (r == nullptr)
        return true;
    if (r->val <= min_left || r->val >= max_right)
        return false;
    if (r->left == r->right)
    {
        auto it = m.find(r->val);
        if (it != end(m) && r != it->second)
        {
            r->left = it->second->left;
            r->right = it->second->right;
            m.erase(it);
        }
    }
    return traverse(r->left, m, min_left, r->val) && traverse(r->right, m, r->val, max_right);
}

TreeNode *canMerge(vector<TreeNode *> &trees)
{
    unordered_map<int, TreeNode *> m;
    unordered_map<int, int> cnt;
    for (auto &t : trees)
    {
        m[t->val] = t;
        ++cnt[t->val];
        ++cnt[t->left ? t->left->val : 0];
        ++cnt[t->right ? t->right->val : 0];
    }
    for (auto &t : trees)
        if (cnt[t->val] == 1)
            return traverse(t, m) && m.size() == 1 ? t : nullptr;
    return nullptr;
}

TreeNode *constructBST(vector<int> &preorder, int &index, int minVal, int maxVal)
{
    if (index >= preorder.size())
    {
        return nullptr;
    }

    int value = preorder[index];
    if (value < minVal || value > maxVal)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(value);
    ++index;

    root->left = constructBST(preorder, index, minVal, value);
    root->right = constructBST(preorder, index, value, maxVal);

    return root;
}

int main()
{
    int n;
    // cout << "Enter the number of BSTs: ";
    cin >> n;

    vector<TreeNode *> trees;

    for (int i = 0; i < n; ++i)
    {
        int numNodes;
        // cout << "Enter the number of nodes in BST " << i + 1 << ": ";
        cin >> numNodes;

        vector<int> preorder;
        // cout << "Enter the preorder traversal for BST " << i + 1 << ": ";
        for (int j = 0; j < numNodes; ++j)
        {
            int nodeValue;
            cin >> nodeValue;
            preorder.push_back(nodeValue);
        }

        int index = 0;
        TreeNode *root = constructBST(preorder, index, INT_MIN, INT_MAX);
        trees.push_back(root);
    }

    // Call the canMerge function to check if the BSTs can be merged
    TreeNode *mergedBST = canMerge(trees);

    if (mergedBST)
    {
        cout << "Merged BST root value: " << mergedBST->val << endl;
    }
    else
    {
        cout << "It is impossible to create a valid BST." << endl;
    }

    // Clean up the memory (deallocate tree nodes, not shown in the original code)
    // Note: Proper memory management is important in a real application.

    return 0;
}
