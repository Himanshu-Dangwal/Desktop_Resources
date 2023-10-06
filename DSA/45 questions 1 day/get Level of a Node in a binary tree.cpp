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


int getLevel(Node* root,int data,int level){     //At beginning the level passed would be 1::
	
		
	if(root == NULL){
		return -1;
	}
	
	
	if(root->data == data){
		return level;
	}

	int lev = getLevel(root->left,data,level+1);
	
	if(lev != -1){
		return lev;
	}
	
	lev = getLevel(root->right,data,level+1);
	
	return lev;
	
}



int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	
	cout<<getLevel(root,3,1)<<endl;
	return 0;
}

