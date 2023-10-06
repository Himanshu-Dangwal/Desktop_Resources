//Serialize and Deserialize A Tree Binary Tree::
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

void inorder(Node* root){
	if(root == NULL)
		return;
		
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);	
}

void serialise(Node* root,FILE* fp){
	
	if(root == NULL){
		fprintf(fp,"%d ",-1);
		return;
	}
	
	fprintf(fp,"%d ",root->data);
	serialise(root->left,fp);
	serialise(root->right,fp);
	
}

void deserialise(Node *&root1,FILE* fp){
	
	int val;
	
	if(!fscanf(fp,"%d ",&val) || val == -1){
		return;
	}
	
	root1 = new Node(val);
	deserialise(root1->left,fp);
	deserialise(root1->right,fp);
	
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(4);
	root->left->left = new Node(3);
	root->right->left = new Node(5);
	root->left->left->right = new Node(6);
	
	FILE* fp = fopen("tree.txt","w");
	if(fp == NULL){
		cout<<"Unable to open the file"<<endl;
		return 0;
	}
	cout<<"Inorder Before Serialisation"<<endl;
	inorder(root);
	cout<<endl;
	serialise(root,fp);
	
	fclose(fp);
	
	fp = fopen("tree.txt","r");
	Node* root1 = NULL;
	deserialise(root1,fp);
	cout<<"Inorder after Deserialisation"<<endl;
	inorder(root1);
	
	return 0;
}

