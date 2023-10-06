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


void inorder(Node* root,int &count,int ans){
	if(root == NULL)
		return;
		
	inorder(root->right,count,ans);
	count += 1;
	if(count == ans)
		cout<<root->data<<endl;
//	cout<<root->data<<" ";
	inorder(root->left,count,ans);
		
}

int main(){
	Node* root = new Node(50);
	root->left = new Node(30);
	root->left->left = new Node(20);
	root->left->right = new Node(40);
	
	root->right = new Node(70);
	root->right->left = new Node(60);
	root->right->right = new Node(80);
	
	int count = 0;
	inorder(root,count,2);
	return 0;
}

