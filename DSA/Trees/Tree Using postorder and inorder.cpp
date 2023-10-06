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

Node* buildTree(int postorder[],int inorder[],int start,int end){
	if(start > end)
		return NULL;
	static int idx = end;	
	
	int current = postorder[idx];
	Node* root = new Node(current);
	idx--;
	
	if(start == end){
		return root;
	}
	
	int pos = search(inorder,current,start,end);
	root->right = buildTree(postorder,inorder,pos+1,end);
	root->left = buildTree(postorder,inorder,start,pos-1);
	return root;
}

void printPostorder(Node *root){
	if(root == NULL)
		return;
	printPostorder(root->left);
	printPostorder(root->right);
	cout<<root->data<<" ";
}

int main(){
	int postorder[] = {4,5,2,6,7,3,1};
	int inorder[] = {4,2,5,1,6,3,7};

	Node* root = buildTree(postorder,inorder,0,6);
	cout<<endl;
	
	printPostorder(root);
	return 0;
}

