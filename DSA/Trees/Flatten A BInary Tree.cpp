#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

struct Node{
	int data;
	Node* left;
	Node* right;
	
	Node(int val){
		this->data = val;
		this->left = NULL;
		this->right = NULL;
	}
};

void flatten(Node* root){
	
	if(root == NULL || (root->left == NULL  &&  root->right == NULL))
		return;
	if(root->left != NULL){
		flatten(root->left);
		Node* temp = root->right;
		
		root->right = root->left;
		root->left = NULL;
		Node* t = root->right;
		while(t->right != NULL){
			t = t->right;
		}
		t->right = temp;
	}	
	flatten(root->right);
}

void PreOrder(Node *root){
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	PreOrder(root->left);
	PreOrder(root->right);	
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->right->left = new Node(4);
	root->right->right = new Node(5);
	
	flatten(root);
	PreOrder(root);
	return 0;
}

