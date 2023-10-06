//Boundary Traversal of a binary tree::
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
		left = right = NULL;
	}
};

bool isLeaf(Node* root){
	if(root->left == NULL && root->right == NULL)
		return true;
		
	return false;	
}


void addLeftNodes(Node* root,vector<int> &ans){
	
	Node *curr = root->left;
	while(curr){
		
		if(!isLeaf(curr)){
			ans.push_back(curr->data);
		}
		if(curr->left)
			curr = curr->left;
		else
			curr = curr->right;	
	}
		
}


void addLeaf(Node* root,vector<int> &ans){
	
	if(isLeaf(root)){
		ans.push_back(root->data);
		return;
	}
	
	if(root->left)
		addLeaf(root->left,ans);
		
	if(root->right)
		addLeaf(root->right,ans);	
}

void addRightNodes(Node* root,vector<int>& ans){
	
	Node* curr = root->right;
	vector<int> res;
	while(curr){
		if(!isLeaf(curr)){
			res.push_back(curr->data);
		}
		
		if(curr->right)
			curr = curr->right;
		else
			curr = curr->left;	
		
	}
	
	for(int i=res.size()-1;i>=0;i--){
		ans.push_back(res[i]);
	}
	return;
}


vector<int> boundaryTraversal(Node* root){
	
	vector<int> ans;
	
	if(root == NULL){
		return ans;
	}
	if(!isLeaf(root))
		ans.push_back(root->data);
	
	addLeftNodes(root,ans);
	addLeaf(root,ans);
	addRightNodes(root,ans);
	
	return ans;
	
}




int main(){
	
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	
	root->left->left = new Node(4);
	root->left->left->right = new Node(5);
	root->left->left->right->left = new Node(6);
	root->left->left->right->right = new Node(7);
	
	root->right->right = new Node(8);
	root->right->right->left = new Node(9);
	
	vector<int> ans = boundaryTraversal(root);


	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	
	return 0;
}

