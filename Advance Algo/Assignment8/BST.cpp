#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

// Definition of a Node in the BST
struct Node
{
    int data;       // Value of the node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child

    // Constructor to initialize a new node
    Node(int val)
    {
        data = val;
        left = NULL;  // Initially, left child is NULL
        right = NULL; // Initially, right child is NULL
    }
};

// Function to insert a new value into the BST
Node* insert(Node* root, int val)
{
    // If the tree/subtree is empty, create a new node
    if (root == NULL)
    {
        return new Node(val);
    }

    // If the value to be inserted is greater than the current node's data,
    // it should be placed in the right subtree
    if (val > root->data)
    {
        root->right = insert(root->right, val);
    }
    // If the value to be inserted is less than the current node's data,
    // it should be placed in the left subtree
    else
    {
        root->left = insert(root->left, val);
    }
    return root; // Return the unchanged root pointer
}

// Function for inorder traversal of the BST
void Inorder(Node* root)
{
    if (root == NULL)
        return; // Base case: if the node is NULL, return

    Inorder(root->left); // Visit left subtree
    cout << root->data << " "; // Visit current node
    Inorder(root->right); // Visit right subtree
}

// Function to find the inorder successor of a given node
Node* InorderSucc(Node* root)
{
    Node* curr = root;
    // The inorder successor is the smallest node in the right subtree
    while (curr && curr->left != NULL)
    {
        curr = curr->left; // Traverse to the leftmost node
    }
    return curr; // Return the leftmost node
}

// Function to delete a node with a given key from the BST
Node* deleteInBST(Node* root, int key)
{
    if (root == NULL) return NULL;  // If key is not found, then return (Nothing will be deleted)
    // If the key is greater than the current node's data, go right
    if (key > root->data)
    {
        root->right = deleteInBST(root->right, key);
    }
    // If the key is less than the current node's data, go left
    else if (key < root->data)
    {
        root->left = deleteInBST(root->left, key);
    }
    else // Key found, this is the node to be deleted
    {
        // Node with only one child or no child
        if (root->right == NULL)
        {
            Node* temp = root->left; // Store left child
            free(root); // Free the current node
            return temp; // Return left child
        }
        else if (root->left == NULL)
        {
            Node* temp = root->right; // Store right child
            free(root); // Free the current node
            return temp; // Return right child
        }
        else // Node with two children
        {
            Node* temp = InorderSucc(root->right); // Get inorder successor
            root->data = temp->data; // Replace current node's data with successor's data
            root->right = deleteInBST(root->right, root->data); // Delete the inorder successor
        }
    }
    return root; // Return the root pointer
}

void Preorder(Node* temp)
{
    if (temp == NULL)
        return;
    cout << temp->data << " ";
    Preorder(temp->left);
    Preorder(temp->right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n; // Read number of elements to insert
    int arr[n]; // Array to store elements
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Read each element
    }
    Node* root = new Node(arr[0]); // Initialize BST with the first element
    for (int i = 1; i < n; i++)
    {
        root = insert(root, arr[i]); // Insert the remaining elements
    }

    Inorder(root); // Perform inorder traversal to display elements in sorted order

    int key;
    cin >> key; // Read the key to be deleted
    Node* temp = deleteInBST(root, key); // Delete the node with the given key
    cout << endl;
    Inorder(temp); // Display the tree after deletion using inorder traversal
    return 0;
}


/*
Complexity Analysis:

1. Insertion (`insert` function)
   - Time Complexity:
     - Average Case: O(log n)
       In a balanced BST, the height of the tree is logarithmic, leading to logarithmic search and insertion time.
     - Worst Case: O(n)
       In a skewed tree, the height can be n, resulting in linear time complexity.

   - Space Complexity:
     - Average Case: O(log n)
       The recursive call stack depth is proportional to the height of the tree.
     - Worst Case: O(n)
       For a skewed tree, the call stack can grow to n.

2. Inorder Traversal (`Inorder` function)
   - Time Complexity: O(n)
     The function visits every node exactly once.

   - Space Complexity:
     - Average Case: O(log n)
       The space used in the recursive call stack is proportional to the height of the tree.
     - Worst Case: O(n)
       In the case of a skewed tree, the call stack can grow to n.

3. Inorder Successor (`InorderSucc` function)
   - Time Complexity: O(h)
     Here, h is the height of the tree. In the average case, it would be O(log n) for a balanced tree, but O(n) in the worst case (skewed tree).

   - Space Complexity: O(1)
     This function does not use any additional space beyond the variables for traversal.

4. Deletion (`deleteInBST` function)
   - Time Complexity:
     - Average Case: O(log n)
       Similar to insertion, the average time complexity is logarithmic if the tree is balanced.
     - Worst Case: O(n)
       For a skewed tree, finding the node to delete can take linear time.

   - Space Complexity:
     - Average Case: O(log n)
       The recursive call stack depth is proportional to the height of the tree.
     - Worst Case: O(n)
       For a skewed tree, the call stack can grow to n.

5. Preorder Traversal (`Preorder` function)
   - Time Complexity: O(n)
     Similar to inorder traversal, every node is visited exactly once.

   - Space Complexity:
     - Average Case: O(log n)
       The recursive call stack depth is proportional to the height of the tree.
     - Worst Case: O(n)
       For a skewed tree, the call stack can grow to n.

6. Main Function Operations
   - Input Reading: O(n) for reading the input for n nodes.
   - Building the BST: O(n log n) in average case and O(n^2) in worst case (for a skewed tree).
   - Deleting a Node: Time complexity same as discussed above.

Summary of Complexities:

| Function           | Time Complexity (Average) | Time Complexity (Worst) | Space Complexity (Average) | Space Complexity (Worst) |
|--------------------|--------------------------|-------------------------|----------------------------|--------------------------|
| `insert`           | O(log n)                 | O(n)                    | O(log n)                   | O(n)                     |
| `Inorder`          | O(n)                     | O(n)                    | O(log n)                   | O(n)                     |
| `InorderSucc`      | O(log n)                 | O(n)                    | O(1)                       | O(1)                     |
| `deleteInBST`      | O(log n)                 | O(n)                    | O(log n)                   | O(n)                     |
| `Preorder`         | O(n)                     | O(n)                    | O(log n)                   | O(n)                     |
| **Main Function**  | O(n log n)               | O(n^2)                  | -                          | -                        |

Conclusion:
The overall efficiency of operations in the BST is significantly impacted by its balance. For practical implementations, self-balancing trees like AVL trees or Red-Black trees are recommended to ensure that the average case time complexities are closer to logarithmic even in the worst scenarios.
*/

