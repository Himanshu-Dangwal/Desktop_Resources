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


int symmetricLevel(TreeNode* root1,TreeNode* root2){
	
	int cnt = 0;
	if(root1 == NULL) return 0;
	queue<TreeNode*> q;
	
	q.push(root1);
	q.push(root2);
	q.push(NULL);
		
	while(!q.empty()){
		
		TreeNode* a= q.front();
		q.pop();
		
		if(a == NULL){
			if(!q.empty())
				q.push(NULL);
			cnt++;
			continue;
		}
		
		TreeNode* b = q.front();
		q.pop();
		
		if(a->data != b->data) return cnt;
		else{
			if(a->left && b->right){
				q.push(a->left);
				q.push(b->right);
			}else if(a->left || b->right){
				if(cnt == 0) return 1;
				return cnt;
			}
			
			if(a->right && b->left){
				q.push(a->right);
				q.push(b->left);
			}else if(a->right || b->left){
				if(cnt == 0) return 1;
				return cnt;
			}
		}		
	}
	return cnt;
}


int main(){

	TreeNode* root1 = new TreeNode(1);
	root1->left = new TreeNode(2);
	root1->right = new TreeNode(2);
	root1->left->left = new TreeNode(4);
	root1->left->right = new TreeNode(-3);	
	root1->right->left = new TreeNode(3);
	root1->right->right = new TreeNode(4);	

	levelOrder(root1);
	cout<<endl;

	cout<<symmetricLevel(root1,root1);
	return 0;
}

