//Maximum sum path in a binary tree::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

struct Node{
	int val;
	Node* left;
	Node* right;
	
	Node(int data){
		this->val = data;
		left = right = NULL;
	}
};

int max_path_sum_util(Node* root,int &ans){
	
	if(root == NULL)
		return 0;
		
	int left = max_path_sum_util(root->left,ans);
	int right = max_path_sum_util(root->right,ans);
	
	int node_max = max(max(root->val,root->val+left+right),max(left+root->val,right+root->val));
	
	ans = max(ans,node_max);
	
	return max(root->val,max(left + root->val , right + root->val));
	
}

int max_path_sum(Node* root){
	
	int ans = INT_MIN;
	max_path_sum_util(root,ans);
	return ans;
	
}


int main(){
	
	Node* root = new Node(1);
	root->left = new Node(6);
	root->left->left = new Node(4);
	root->right = new Node(3);
	root->right->left = new Node(5);
	root->right->right = new Node(1);
	
	cout<<max_path_sum(root)<<endl;

	return 0;
}

