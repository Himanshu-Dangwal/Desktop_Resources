//Diameter of a binary tree:::
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

int count_all_nodes(Node* root){
	if(root == NULL)
		return 0;
	return count_all_nodes(root->left) + count_all_nodes(root->right) + 1;
}

int getHeight(Node *root){
	if(root == NULL){
		return 0;
	}
	return max(getHeight(root->left),getHeight(root->right)) + 1;
}

int getDiameter(Node *root){
	if(root == NULL)
		return 0;
	//Including Root::
	int lHeight = getHeight(root->left);
	int rHeight = getHeight(root->right);
	int Diameter1 = lHeight + rHeight +1;
	
	int lDiameter = getDiameter(root->left);
	int rDiameter = getDiameter(root->right);
	
	return max(Diameter1,max(lDiameter,rDiameter));
}

bool isBalanced(Node *root){
	if(root == NULL)
		return true;
	if(!isBalanced(root->left)){
		return false;
	}
	
	if(!isBalanced(root->right)){
		return false;
	}
	
	int lh = getHeight(root->left);
	int rh = getHeight(root->right);
	
	if(abs(lh - rh) <=1 ){
		return true;
	}
	return false;
}

//Optimised Way to calcultae diameter::

int calculate_Diameter(Node* root,int *height){
	if(root == NULL){
		*height = 0;
		return 0;	
	}
	int lh = 0;
	int rh = 0;
	
	int left_dia = calculate_Diameter(root->left,&lh);
	int right_dia = calculate_Diameter(root->right,&rh);
	
	int curr_height = max(lh,rh) + 1;
	curr_dia = lh + rh +1;
	
	return max(curr_dia,max(left_dia,right_dia));	
}

int main(){
	struct Node* root = new Node(1);
	root->left = new Node(2);
//	cout<<"val";
//	root->right = new Node(3);
	root->left->left = new Node(4);
//	root->left->right = new Node(5);
//	root->right->left = new Node(6);
//	root->right->right = new Node(7);
//	root->left->left->left = new Node(8);
//	root->left->left->right = new Node(9);
//	root->left->left->right->right = new Node(10);

	if(isBalanced(root)){
		cout<<"Tree is Balanced"<<endl;
	}else{
		cout<<"Tree is not balanced"<<endl;
	}
//	int count = count_all_nodes(root);
//	cout<<count<<endl;
//	int height = getHeight(root);
//	cout<<height<<endl;
//	int Diameter = getDiameter(root);
//	cout<<Diameter<<endl;	
	return 0;
}

