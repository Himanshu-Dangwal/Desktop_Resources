//Check if BST's are Identical or not::
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

bool check(Node* root1,Node* root2){
	if(root1 == NULL && root2 == NULL)
		return true;
		
	if(root1 !=NULL && root2 != NULL){
		if(root1->data == root2->data && check(root1->left,root2->left) && check(root1->right,root2->right)){
			return true;
		}
		return false;
	}	
	return false;
}

int main(){
	Node* root1 = new Node(10);
	root1->left = new Node(6);
	root1->left->right = new Node(8);
	root1->left->right->left = new Node(7);
	root1->right = new Node(15);
	root1->right->left = new Node(12); 
	
	
	Node* root2 = new Node(10);
	root2->left = new Node(6);
	root2->left->right = new Node(8);
	root2->left->right->left = new Node(7);
	root2->right = new Node(15);
	root2->right->left = new Node(13); 
	
	if(check(root1,root2)){
		cout<<"true"<<endl;
	}
	else{
		cout<<"false"<<endl;	
	}
	
	
	return 0;
}

