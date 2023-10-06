//Binary Trees::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

struct Node{
		int data;
		struct Node* left;
		struct Node* right;
		
		Node(int val){
			this->data = val;
			this->left = NULL;
			this->right = NULL;
		}
};

void preorder(struct Node* root){
//	cout<<"inside Preorder";
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node *root){
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
  

void postorder(Node *root){
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}


int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
	struct Node* root = new Node(1);
	root->left = new Node(2);
//	cout<<"val";
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	cout<<"Preorder  :: ";
	preorder(root);
	cout<<endl;
	cout<<"Inorder   :: ";
	inorder(root);
	cout<<endl;
	cout<<"Postorder :: ";
	postorder(root);
	return 0;
}


//
//// C++ program for different tree traversals
//#include <iostream>
//using namespace std;
//
///* A binary tree node has data, pointer to left child
//and a pointer to right child */
//struct Node {
//	int data;
//	struct Node *left, *right;
//	Node(int data)
//	{
//		this->data = data;
//		left = right = NULL;
//	}
//};
//
///* Given a binary tree, print its nodes according to the
//"bottom-up" postorder traversal. */
//void printPostorder(struct Node* node)
//{
//	if (node == NULL)
//		return;
//
//	// first recur on left subtree
//	printPostorder(node->left);
//
//	// then recur on right subtree
//	printPostorder(node->right);
//
//	// now deal with the node
//	cout << node->data << " ";
//}
//
///* Given a binary tree, print its nodes in inorder*/
//void printInorder(struct Node* node)
//{
//	if (node == NULL)
//		return;
//
//	/* first recur on left child */
//	printInorder(node->left);
//
//	/* then print the data of node */
//	cout << node->data << " ";
//
//	/* now recur on right child */
//	printInorder(node->right);
//}
//
///* Given a binary tree, print its nodes in preorder*/
//void printPreorder(struct Node* node)
//{
//	if (node == NULL)
//		return;
//
//	/* first print data of node */
//	cout << node->data << " ";
//
//	/* then recur on left sutree */
//	printPreorder(node->left);
//
//	/* now recur on right subtree */
//	printPreorder(node->right);
//}
//
///* Driver program to test above functions*/
//int main()
//{
//	struct Node* root = new Node(1);
//	root->left = new Node(2);
//	root->right = new Node(3);
//	root->left->left = new Node(4);
//	root->left->right = new Node(5);
//
//	cout << "\nPreorder traversal of binary tree is \n";
//	printPreorder(root);
//
//	cout << "\nInorder traversal of binary tree is \n";
//	printInorder(root);
//
//	cout << "\nPostorder traversal of binary tree is \n";
//	printPostorder(root);
//
//	return 0;
//}

