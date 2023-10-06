//Count all Nodes in A  binary tree::;
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
		
	Node(int val){
		this->data = val;
		this->left = NULL;
		this->right = NULL;
	}
};

int count_all_nodes(Node* root){
	if(root == NULL)
		return 0;
	return count_all_nodes(root->left) + count_all_nodes(root->right) + root->data;
}

int main(){
	struct Node* root = new Node(1);
	root->left = new Node(2);
//	cout<<"val";
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	int count = count_all_nodes(root);
	cout<<count<<endl;
	return 0;
}

