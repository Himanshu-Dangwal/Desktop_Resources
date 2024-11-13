#include <bits/stdc++.h>
using namespace std;
// #pragma GCC target("popcnt")
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
// find_by_order() 
// order_of_key()
int ans;

void dfs(Node* u, int dep) {
    ans += dep;
    if (u->left) dfs(u->left, dep + 1);
    if (u->right) dfs(u->right, dep + 1);
}

int sumDepths(Node* root) {
    ans = 0;
    dfs(root, 0);
    return ans;
}


// Number of nodes vs sumofDepth
pair<int, int> dfs2(Node* root) {
    pair<int, int> curr = make_pair(1, 0);
    if (root->left) {
        pair<int, int> leftAns = dfs2(root->left);
        curr.first += leftAns.first;
        curr.second += leftAns.second + leftAns.first;
    }

    if (root->right) {
        pair<int, int> rightAns = dfs2(root->right);
        curr.first += rightAns.first;
        curr.second += rightAns.second + rightAns.first;
    }

    ans += curr.second;
}

int allSubtreeDep(Node* root) {
    ans = 0;
    dfs2(root);
    return ans;
}

int main()
{

    return 0;
}