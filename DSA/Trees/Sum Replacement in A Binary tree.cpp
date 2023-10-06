//Sum Replacement in a Binary Tree::
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
	return count_all_nodes(root->left) + count_all_nodes(root->right) + 1;
}

void levelOrderTraversal(Node* root){
	Node* temp = root;
	queue<Node*> q;
	q.push(temp);
	while(!q.empty()){
		Node* curr = q.front();
		q.pop();
		cout<<curr->data<<" ";
		if(curr->left != NULL)
			q.push(curr->left);
		if(curr->right != NULL)
			q.push(curr->right);
	}
}

void sumReplacement(Node *root){
	if(root == NULL)
		return;
	
	sumReplacement(root->left);
	sumReplacement(root->right);
	
	if(root->left != NULL){
		root->data += root->left->data;
	}
	if(root->right != NULL){
		root->data += root->right->data;
	}
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
	sumReplacement(root);
	
	levelOrderTraversal(root);
//	int count = count_all_nodes(root);
//	cout<<count<<endl;
	return 0;
}

