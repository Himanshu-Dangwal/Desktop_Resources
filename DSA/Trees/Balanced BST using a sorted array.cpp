//Given a sorted array make a Balanced BST using it::
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
		data= val;
		left = NULL;
		right = NULL;
	}
};

Node* make_Balanced_BST(int arr[],int s,int e){
	if(s > e)
		return NULL;
	
	if(s == e){
		Node* temp = new Node(arr[s]);
		return temp;
	}
	
	int mid = (s+e)/2;
	cout<<mid<<endl;
	Node* root = new Node(arr[mid]);
	root->left = make_Balanced_BST(arr,s,mid-1);
	root->right = make_Balanced_BST(arr,mid+1,e);
	
	return root;
}

void Inorder(Node* root){
	if(root == NULL){
		return;
	}
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
	Node* root = make_Balanced_BST(arr,0,n-1);
	Inorder(root);
	return 0;
}

