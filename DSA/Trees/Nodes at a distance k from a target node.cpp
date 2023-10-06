//Print all nodes at a distance k from a target node given to us::
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

/*
						1
				5				2
							
			6				3		4					
				
				7
				
			8		9	
*/

void printSubtree(Node *root,int k){
	if(root == NULL || k<0)
		return;
	if(k==0)
		cout<<root->data<<" ";
	
	printSubtree(root->left,k-1);
	printSubtree(root->right,k-1);		
}

int printNodesAtK(Node* root,int target,int k){
	if(root == NULL){
		return -1;
	}
	if(root->data == target){
		printSubtree(root,k);
		return 0;
	}
	
	int dl = printNodesAtK(root->left,target,k);
	if(dl != -1){
		if(dl+1 == k){
			cout<<root->data<<" ";
		}else{
			printSubtree(root->right,k-dl-2);
		}
		return 1+dl;
	}
	
	int dr = printNodesAtK(root->right,target,k);
	if(dr != -1){
		if(dr+1 == k){
			cout<<root->data<<" ";
		}else{
			printSubtree(root->left,k-dr-2);
		}
		return 1+dr;
	}
	return -1;
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(5);
	root->left->left = new Node(6);
	root->left->left->right = new Node(7);
	root->left->left->right->left = new Node(8);
	root->left->left->right->right = new Node(9);
	
	root->right = new Node(2);
	root->right->left = new Node(3);
	root->right->right = new Node(4);
	
	int target = 5;
	int k = 3;
	
	printNodesAtK(root,target,k);

	return 0;
}

