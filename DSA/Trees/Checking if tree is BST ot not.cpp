//Checking if a tree is BST or not::
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

bool check(Node* root,int min_allowed,int max_allowed){
	if(root == NULL)
		return true;
	
	if(root->data > min_allowed  &&  root->data < max_allowed){
		if(check(root->left,min_allowed,root->data) && check(root->right,root->data,max_allowed))
			return true;;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

//	Node* root = new Node(4);
//	root->left = new Node(2);
//	root->left->left = new Node(1);
//	root->right = new Node(7);
//	root->right->left = new Node(6);
//	root->right->right = new Node(8);

	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);	
	if(check(root,INT_MIN,INT_MAX)){
		cout<<"Yes"<<endl;	
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}

