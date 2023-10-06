//Zig Zag Traversal In a tree::
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

void zigZagTraversal(Node* root){
	if(root == NULL)
		return;
	
	stack<Node*> curr_level;
	stack<Node*> next_level;
	
	curr_level.push(root);
	bool ltr = 	true;
	
	while(!curr_level.empty()){
		Node* temp = curr_level.top();
		curr_level.pop();
		
		if(temp != NULL){
			cout<<temp->data<<" ";
			
			if(ltr){
				if(temp->left != NULL){
					next_level.push(temp->left);
				}
				if(temp->right != NULL){
					next_level.push(temp->right);
				}
			}else{
				if(temp->right != NULL){
					next_level.push(temp->right);
				}
				if(temp->left != NULL){
					next_level.push(temp->left);
				}
			}
		}
		if(curr_level.empty()){
			ltr = !ltr;
			swap(curr_level,next_level);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//Input a tree 
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
//	root->left->left = new Node(4);
	root->left->right = new Node(4);
//	root->right->left = new Node(6);
	root->right->right = new Node(5);
	root->left->right->left = new Node(6);
	root->left->right->right = new Node(7);
	
	zigZagTraversal(root); 
	return 0;
}

