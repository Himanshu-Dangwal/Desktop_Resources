void inorder(Tree *root)
{

    if (root == NULL)
        return NULL;
    inorder(root->left);
    cout << root->val;
    inorder(root->right);
}