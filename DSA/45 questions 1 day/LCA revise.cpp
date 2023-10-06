//LCA revise::

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


Node* LCA(Node* root,int n1,int n2){
	
	if(root == NULL)
		return NULL;
	
	if(root->data == n1 || root->data == n2){
		return root;
	}
	
	Node* leftLCA = LCA(root->left,n1,n2);
	Node* rightLCA = LCA(root->right,n1,n2);
	
	if(leftLCA != NULL  &&   rightLCA != NULL){
		return root;
	}
	if(leftLCA == NULL && rightLCA == NULL){
		return NULL;
	}
	if(leftLCA == NULL)
		return rightLCA;
	return leftLCA;
}

int main(){
	
	return 0;
}

