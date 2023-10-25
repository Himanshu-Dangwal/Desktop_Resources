#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

Node *buildTree(string str)
{
    if (str.length() == 0 || str == "N")
        return nullptr;
    vector<string> s;

    stringstream ss(str);
    string token;
    while (ss >> token)
    {
        s.push_back(token);
    }

    Node *root = new Node(stoi(s[0]));
    queue<Node *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < s.size())
    {
        Node *currNode = q.front();
        q.pop();

        if (i < s.size() && s[i] != "N")
        {
            currNode->left = new Node(stoi(s[i]));
            q.push(currNode->left);
        }

        i++;
        if (i < s.size() && s[i] != "N")
        {
            currNode->right = new Node(stoi(s[i]));
            q.push(currNode->right);
        }

        i++;
    }

    return root;
}

int searchInBST(Node *root, int key)
{
    if (root == nullptr)
        return -1;

    if (key < root->data)
        return searchInBST(root->left, key);
    if (key > root->data)
        return searchInBST(root->right, key);
    if (key == root->data)
        return 1;

    return -1;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t > 0)
    {
        int N;
        cin >> N;
        string s;
        cin.ignore();
        getline(cin, s);

        Node *root = buildTree(s);
        int key;
        cin >> key;

        int ans = searchInBST(root, key);
        cout << ans << endl;
        t--;
    }
    return 0;
}
