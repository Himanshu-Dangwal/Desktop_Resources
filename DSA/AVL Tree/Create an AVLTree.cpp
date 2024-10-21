#include <bits/stdc++.h>
using namespace std;
class AVLtree
{
public:
    int key;
    AVLtree *left;
    AVLtree *right;
    int height;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getHeight(AVLtree *tree)
{
    if (tree == NULL)
        return 0;
    return tree->height;
}

AVLtree *newNode(int key)
{
    AVLtree *tree = new AVLtree();
    tree->key = key;
    tree->left = NULL;
    tree->right = NULL;
    tree->height = 1;
    return (tree);
}

AVLtree *leftRotate(AVLtree *t1)
{
    AVLtree *curr = t1->right;
    AVLtree *t2 = curr->left;

    curr->left = t1;
    t1->right = t2;

    t1->height = max(getHeight(t1->left),
                     getHeight(t1->right)) +
                 1;
    curr->height = max(getHeight(curr->left),
                       getHeight(curr->right)) +
                   1;
    return curr;
}

AVLtree *rightRotate(AVLtree *t1)
{
    AVLtree *curr = t1->left;
    AVLtree *t2 = curr->right;

    curr->right = t1;
    t1->left = t2;

    t1->height = max(getHeight(t1->left),
                     getHeight(t1->right)) +
                 1;
    curr->height = max(getHeight(curr->left),
                       getHeight(curr->right)) +
                   1;

    return curr;
}

int getBalance(AVLtree *tree)
{
    if (tree == NULL)
        return 0;
    return getHeight(tree->left) - getHeight(tree->right);
}

AVLtree *insertNode(AVLtree *tree, int key)
{
    if (tree == NULL)
        return (newNode(key));

    if (key < tree->key)
        tree->left = insertNode(tree->left, key);
    else if (key > tree->key)
        tree->right = insertNode(tree->right, key);
    else
        return tree;

    tree->height = 1 + max(getHeight(tree->left),
                           getHeight(tree->right));

    int balance = getBalance(tree);

    if (balance > 1 && key < tree->left->key)
        return rightRotate(tree);

    if (balance < -1 && key > tree->right->key)
        return leftRotate(tree);

    if (balance > 1 && key > tree->left->key)
    {
        tree->left = leftRotate(tree->left);
        return rightRotate(tree);
    }

    if (balance < -1 && key < tree->right->key)
    {
        tree->right = rightRotate(tree->right);
        return leftRotate(tree);
    }

    return tree;
}

void preOrder(AVLtree *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Driver Code
int main()
{
    AVLtree *tree = NULL;
    // Input array represents the order of insertion of nodes in the tree
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; ++i)
        cin >> A[i];

    for (int i = 0; i < n; ++i)
        tree = insertNode(tree, A[i]);

    preOrder(tree);

    return 0;
}