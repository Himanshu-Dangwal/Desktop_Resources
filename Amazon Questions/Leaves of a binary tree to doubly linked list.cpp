#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int ,  null_type ,  less<int>,  rb_tree_tag ,  tree_order_statistics_node_update>


//   order_of_key(x)   Number of items strictrly less than x
//   find_by_order(x)  Find the kth largest element(countingg from zero)
class Node{
	public:
		Node* left;
		Node* right;
		int data;
		
		Node(int val){
			data = val;
			left = NULL;
			right = NULL;
		}
};


Node* doubly_linked_list(Node* root,Node* &head){
	
	if(root == NULL) return NULL;
	if(root->left == NULL && root->right == NULL){
		root->right = head;
		if(head != NULL){
			head->left = root;
		}
		head = root;
		return NULL;
	}
	
	root->right = doubly_linked_list(root->right,head);
	root->left = doubly_linked_list(root->left,head);
	return root;
}

void traversal(Node* head){
	while(head != NULL){
		cout<<head->data<<" -> ";
		head = head->right;
	}
	cout<<"NULL";
}

void inorder_traversal(Node* root){
	if(root == NULL) return;
	inorder_traversal(root->left);
	cout<<root->data<<" ";
	inorder_traversal(root->right);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Node *head = NULL; 
    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->right = new Node(6); 
    root->left->left->left = new Node(7); 
    root->left->left->right = new Node(8); 
    root->right->right->left = new Node(9); 
    root->right->right->right = new Node(10); 

	inorder_traversal(root);
	cout<<endl;
	root = doubly_linked_list(root,head);
	inorder_traversal(root);
	cout<<endl;
	traversal(head);
	return 0;
}


