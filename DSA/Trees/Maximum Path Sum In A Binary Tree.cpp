//Maximum Path SUm In a Binary Tree
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

//int max_val = INT_MIN;

//int max_path_sum(Node* root){
//	if(root == NULL){
//		return 0;
//	}
//	int left_sum = max_path_sum(root->left);
//	int right_sum = max_path_sum(root->right);
//	
//	root->data += max(left_sum,right_sum);
//	if(root->data > max_val){
//		max_val = root->data;
//	}
//	return root->data;
//}


int max_path_util(Node* root,int &ans){
	
	if(root == NULL) return 0;
	
	int left = max_path_util(root->left,ans);
	int right = max_path_util(root->right,ans);
	
	int Node_max = max(max(root->data,left+root->data),max(root->data+right,left+right+root->data));
	
	ans = max(ans,Node_max);
	
	return max(root->data,max(left+root->data,right+root->data));
	
}

int max_path_sum(Node* root){
	if(root == NULL) return 0;
	int ans = 0;
	int temp = max_path_util(root,ans);
	
	return ans;
}


int main(){
	Node *root = new Node(1);
	root->left = new Node(-12);
	root->right = new Node(3);
	root->right->left = new Node(5);
	root->right->right = new Node(-6);
	root->left->left = new Node(4);
	
	cout<<max_path_sum(root);
	
	return 0;
}



// root->data || left + root->data || right + root->data || left + root->data + right



