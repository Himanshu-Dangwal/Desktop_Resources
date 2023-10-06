//shortest Distance Between 2 node is a Binary tree::

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
	
		Node(int val){
			this->data = val;
			this->left = NULL;
			this->right = NULL;
		}
}; 

void preorder(Node* root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

Node* LCA(Node* root,int n1,int n2){
	if(root == NULL){
		return NULL;
	}
	
	if(root->data == n1 || root->data == n2){
		return root;
	}
	
	Node* left_lca = LCA(root->left,n1,n2);
	Node* right_lca = LCA(root->right,n1,n2);
	
	if(left_lca!=NULL && right_lca!=NULL){
		return root;
	}
	if(left_lca==NULL && right_lca == NULL){
		return NULL;
	}
	if(left_lca!=NULL){
		return left_lca;
	}
	return right_lca;
}

int getDistance(Node *root,int n,int distance){
	if(root == NULL){
		return -1;
	}
	if(root->data == n){
		return distance;
	}
	int left = getDistance(root->left,n,distance+1);
	if(left != -1){
		return left;
	}
	return getDistance(root->right,n,distance+1);
}

int shortest_distance(Node *root,int n1,int n2){
	Node* lca = LCA(root,n1,n2);
	
	int d1 = getDistance(lca,n1,0);
	int d2 = getDistance(lca,n2,0);
	
	return d1+d2; 
}

int main(){
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->right = new Node(4);
	root->right->left = new Node(5);
	root->right->left->left = new Node(6);
	root->right->right = new Node(7);
	
	cout<<"Prerder Traversal :"<<endl;
	preorder(root);
	cout<<endl;
	int n1 = 6;
	int n2 = 7;
	cout<<"Shortest Distance between n1 and n2 is ::"<endl;
	cout<<shortest_distance(root,n1,n2)<<endl;
	return 0;
}

