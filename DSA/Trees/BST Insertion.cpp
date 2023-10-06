//Binary Search Trees::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

struct Node{
	int data;
	Node *left,*right;
	
	Node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};

Node* insert(Node* root,int val){
	if(root == NULL){
		return new Node(val);
	}
	
	if(val > root->data){
		root->right = insert(root->right,val);
	}else{
		root->left = insert(root->left,val);
	}
	return root;
}

void Inorder(Node *root){
	if(root == NULL)
		return;
	
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	Node* root = new Node(arr[0]);
	for(int i=1;i<n;i++){
		root = insert(root,arr[i]);
	}
	
	Inorder(root);
//	cout<<root->left->data;
	return 0;
}

