//Get level of a node in a tree::
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


int getLevel(Node* root,Node* temp,int level){     //At beginning the level passed would be 1::
	
		
	if(root == NULL){
		return -1;
	}
	
	
	if(root == temp){
		return level;
	}

	int lev = getLevel(root->left,temp,level+1);
	
	if(lev != -1){
		return lev;
	}
	
	lev = getLevel(root->right,temp,level+1);
	
	return lev;
	
}


void getCousinsUtil(Node* root,Node* temp,int level){
	
	if(root == NULL ||  level < 2){
		return;
	}
	
	if(level == 2){
		if(root->left == temp  ||  root->right == temp){
			return;
		}
		if(root->left != NULL){
			cout<<root->left->data<<" ";
		}
		if(root->right != NULL){
			cout<<root->right->data<<" ";
		}
		return;
	}
	
	else if(level > 2){
		getCousinsUtil(root->left,temp,level-1);
		getCousinsUtil(root->right,temp,level-1);
		return;
	}
	
}


void getCousins(Node* root,Node* temp){
	
	int levelOfTarget = getLevel(root,temp,1);
	cout<<levelOfTarget<<endl;
	getCousinsUtil(root,temp,levelOfTarget);
	
	return;
	
}


int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	
	root->left->left->left = new Node(8);
	root->left->left->right = new Node(9);
	root->left->right->right = new Node(10);
	
	root->right->left->right = new Node(11);
	root->right->right->right = new Node(12);
	
	getCousins(root,root->left->left->left);   //get Cousins of node having data = 5::
	
	return 0;
}

