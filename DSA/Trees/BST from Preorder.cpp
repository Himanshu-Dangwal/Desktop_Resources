//Build BST from preorder traversal given to us
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
		data = val;
		left = NULL;
		right = NULL;
	}
};

void Preorder(Node * root){
	if(root == NULL)
		return ;
		
	cout<<root->data<<" ";
	Preorder(root->left);
	Preorder(root->right);	
}

Node* constructBST(int preorder[],int *preorderIdx,int key,int min_val,int max_val,int n){
	
	if(*preorderIdx >= n)
		return NULL;
	
	Node* root = NULL;
	if(key > min_val && key < max_val){
		root = new Node(key);
		
		*preorderIdx = *preorderIdx + 1;
		
		if(*preorderIdx < n){
			root->left = constructBST(preorder,preorderIdx,preorder[*preorderIdx],min_val,key,n);
		}
		
		if(*preorderIdx < n){
			root->right = constructBST(preorder,preorderIdx,preorder[*preorderIdx],key,max_val,n);
		}
		
	}
	return root;
}

void Inorder(Node *root){
	if(root == NULL){
		return ;
	}
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int preorder[] = {10,2,1,13,11};
	int n = 5;
	int preorderIdx = 0;
	
	Node* root = constructBST(preorder,&preorderIdx,preorder[0],INT_MIN,INT_MAX,5);
	cout<<endl;
	Preorder(root);
	cout<<endl;
	Inorder(root);
	return 0;
}

