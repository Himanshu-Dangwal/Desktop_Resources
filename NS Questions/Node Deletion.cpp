#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

int minValue(Node *root)
{
    int minv = root->data;
    while (root->left != nullptr)
    {
        minv = root->left->data;
        root = root->left;
    }
    return minv;
}

Node *buildTree(string str)
{
    if (str.length() == 0 || str[0] == 'N')
    {
        return nullptr;
    }

    vector<string> ip;
    istringstream iss(str);
    do
    {
        string word;
        iss >> word;
        ip.push_back(word);
    } while (iss);

    Node *root = new Node(stoi(ip[0]));
    queue<Node *> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < ip.size())
    {
        Node *currNode = q.front();
        q.pop();

        if (ip[i] != "N")
        {
            currNode->left = new Node(stoi(ip[i]));
            q.push(currNode->left);
        }

        i++;
        if (i >= ip.size())
        {
            break;
        }

        if (ip[i] != "N")
        {
            currNode->right = new Node(stoi(ip[i]));
            q.push(currNode->right);
        }

        i++;
    }

    return root;
}

void printInorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

Node *deleteInBST(Node *root, int key)
{
    if (root == nullptr)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteInBST(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteInBST(root->right, key);
    }
    else
    {
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        root->data = minValue(root->right);
        root->right = deleteInBST(root->right, root->data);
    }

    return root;
}

int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        int N;
        cin >> N;
        string s;
        cin.ignore();
        getline(cin, s);
        int x;
        cin >> x;
        Node *root = buildTree(s);
        root = deleteInBST(root, x);
        printInorder(root);
        cout << endl;
        t--;
    }
    return 0;
}
