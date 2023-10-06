//Build Tree From preorder and Inorder:::
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

int search(int inorder[],int val,int start,int end){
	for(int i=start;i<=end;i++){
		if(inorder[i] == val)
			return i;
	}
	return -1;
}

Node* buildTree(int preorder[],int inorder[],int start,int end){
	if(start > end)
		return NULL;
	static int idx = 0;	
	
	int current = preorder[idx];
	Node* root = new Node(current);
	idx++;
	
	if(start == end){
		return root;
	}
	
	int pos = search(inorder,current,start,end);
	root->left = buildTree(preorder,inorder,start,pos-1);
	root->right = buildTree(preorder,inorder,pos+1,end);
	return root;
}

void printInorder(Node *root){
	if(root == NULL)
		return;
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

int main(){
	int preorder[] = {1,2,4,5,3,6,7};
	int inorder[] = {4,2,5,1,6,3,7};

	Node* root = buildTree(preorder,inorder,0,6);
	cout<<endl;
	
	printInorder(root);
	return 0;
}

