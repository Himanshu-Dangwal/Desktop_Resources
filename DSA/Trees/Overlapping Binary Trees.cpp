#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

struct TreeNode{
	int data;
	TreeNode* left;
	TreeNode* right;
	
	TreeNode(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};


TreeNode* getOverlapped(TreeNode* root1,TreeNode* root2){
	
	if(root1 == NULL && root2 != NULL) return root2;
		
	if(root2 != NULL && root1 != NULL){
		
		if(root2->left == NULL && root1->left != NULL){
			root2->left = root1->left;
		}else{
			TreeNode* leftSide = getOverlapped(root1->left,root2->left);
			root2->left = leftSide;
		}
			
			
		if(root2->right == NULL && root1->right != NULL){
			root2->right = root1->right;
		}else{
			TreeNode* rightSide = getOverlapped(root1->right,root2->right);
			root2->right = rightSide;
		}	
	}	
	
	return root2;
}

void levelOrder(TreeNode* root){
	TreeNode* temp = root;
	queue<TreeNode*> q;
	q.push(temp);
	while(!q.empty()){
		TreeNode* curr = q.front();
		q.pop();
		cout<<curr->data<<" ";
		if(curr->left != NULL)
			q.push(curr->left);
		if(curr->right != NULL)
			q.push(curr->right);
	}
}

int main(){
	
	TreeNode* root2 = new TreeNode(1);
	root2->left = new TreeNode(2);
	root2->right = new TreeNode(2);
	root2->left->right = new TreeNode(3);
//	root2->right->left = new TreeNode(4);	
//	root2->right->right = new TreeNode(6);

	levelOrder(root2);
	
	TreeNode* root1 = new TreeNode(2);
	root1->left = new TreeNode(5);
	root1->right = new TreeNode(7);
	root1->left->left = new TreeNode(9);
	root1->right->left = new TreeNode(18);	
	root1->right->right = new TreeNode(3);
	root1->left->left->left = new TreeNode(11);	


	cout<<endl;
	levelOrder(root1);
	cout<<endl;

		
	TreeNode* ans = getOverlapped(root1,root2);

//	cout<<ans->data;
	
	levelOrder(ans);

	return 0;
}

