#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

struct node{
	node* left;
	node* right;
	int data;
};

node* findMax(node* root){
	node* curr = root;
	while(curr->right != NULL){
		curr = curr->right;
	}
	return curr;
}


node* Delete(node* root,node* delNode){
	node* temp;
	if(root == NULL) return root;
	else if(root->data > delNode->data) root->left = Delete(root->left,delNode);
	else if(root->data < delNode->data) root->right = Delete(root->right,delNode);
	
	else{
		if(root->left && rott->right){
			temp = findMax(root->left);
			root->data = temp->data;
			root->left = Delete(root->left,delNode);
		}else{
			temp = root;
			if(root->left == NULL){
				root = root->right;
			}
			if(root->right == NULL){
				root = root->left;
			}
			delete(temp);
		}
	}
	return root;
}




int main(){
	//Insert elements::
	return 0;
}

