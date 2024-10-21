#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;

    TreeNode(int x)
    {
        this->val = x;
        left = right = NULL;
    }
};

TreeNode *deserialize(string data)
{
    if (!data.length())
        return NULL;
    string rootVal = "";
    int i = 0;
    for (; i < data.length(); i++)
    {
        if (data[i] == ',')
        {
            i++;
            break;
        }
        rootVal += data[i];
    }
    // cout << rootVal << endl;
    TreeNode *root = new TreeNode(stoi(rootVal));
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        string leftVal = "", rightVal = "";

        // Left Val
        while (i < data.length())
        {
            if (data[i] == ',')
            {
                i++;
                break;
            }
            leftVal += data[i];
            i++;
        }
        if (leftVal == "#")
        {
            curr->left = NULL;
        }
        else
        {
            // cout << leftVal << endl;
            curr->left = new TreeNode(stoi(leftVal));
            q.push(curr->left);
        }

        // Right Val
        while (i < data.length())
        {
            if (data[i] == ',')
            {
                i++;
                break;
            }
            rightVal += data[i];
            i++;
        }

        if (rightVal == "#")
        {
            curr->right = NULL;
        }
        else
        {
            // cout << rightVal << endl;
            curr->right = new TreeNode(stoi(rightVal));
            q.push(curr->right);
        }
    }

    return root;
}

int depth(TreeNode *root)
{
    if (!root)
        return 0;

    return max(depth(root->left), depth(root->right)) + 1;
}

void levelOrder(TreeNode *root)
{
    TreeNode *temp = root;
    queue<TreeNode *> q;
    q.push(temp);
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        cout << curr->val << " ";
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
}

int main()
{
    // Assuming that the input (Tree) will be given as a serialized string
    string serialized;
    cin >> serialized;

    TreeNode *root = deserialize(serialized);

    // levelOrder(root);

    cout << depth(root);
    return 0;
}