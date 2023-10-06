//Largest BST in BT::
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

struct Info{
	int min_val;
	int max_val;
	int size;
	int ans; 
	bool isBST;
};

Info largestBSTinBT(Node *root){
	if(root == NULL){
		return {INT_MAX,INT_MIN,0,0,true};
	}
	if(root->left == NULL && root->right == NULL){
		return {root->data,root->data,1,1,true};
	}
	Info left = largestBSTinBT(root->left);
	Info right = largestBSTinBT(root->right);
	
	Info curr;
	curr.size = left.size + right.size + 1;
	
	if(left.isBST && right.isBST && root->data > left.max_val && root->data < right.min_val){
		curr.max_val = max(root->data,max(left.max_val,right.max_val));
		curr.min_val = min(root->data,min(left.min_val,right.min_val));
		
		curr.isBST = true;
		curr.ans = curr.size;
		return curr;
	}
	
	curr.ans = max(left.ans,right.ans);
	curr.isBST = false;
	return curr;
	
}

int main(){
	Node *root = new Node(15);
	root->left = new Node(10);
	root->left->left = new Node(5);
	root->right = new Node(30);
	Info temp = largestBSTinBT(root);
	cout<<temp.ans<<endl;
	return 0;
}

