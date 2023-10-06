//Binary Search Trees::
//Deletion
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

Node* InorderSucc(Node* root){
	Node* curr = root;
	while(curr && curr->left != NULL){
		curr = curr->left;
	}
	return curr;
}

Node* deleteInBST(Node* root,int key){
	if(key > root->data){
		root->right = deleteInBST(root->right,key);
	}else if(key < root->data){
		root->left = deleteInBST(root->left,key);
	}else{
		if(root->right == NULL){
			Node* temp =root->left;
			free(root);
			return temp;
		}
		else if(root->left == NULL){
			Node* temp = root->right;
			free(root);
			return temp;
		}
		else{
			Node* temp = InorderSucc(root->right);
			root->data = temp->data;
			root->right = deleteInBST(root->right,root->data);
		}
	}
	return root;
}

void Preorder(Node *temp){
	if(temp == NULL)
		return;
	cout<<temp->data<<" ";
	Preorder(temp->left);
	Preorder(temp->right);
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
	
	int key;
	cin>>key;
	Node *temp = deleteInBST(root,key);
	cout<<endl;
	Preorder(temp);
	cout<<endl;
	Inorder(temp);
//	cout<<root->left->data;
	return 0;
}

