////Height::
//#include<bits/stdc++.h>
//using namespace std;
//#define endl "\n"
//#define MOD 1000000007
//typedef long long ll;
//
//int height(Node* root){
//	
//	if(root->left == NULL && root->right == NULL){
//		return 0;
//	}
//	
//	if(root == NULL){
//		return 0;
//	}
//	int l1 = 0;
//	int l2 = 0;
//
//	l1 = height(root->left);
//	
//	l2 = height(root->right);
//		
//	return max(l1,l2) + 1;		 
//}
//
//
//int depth(Node* root,Node* key){
//	
//	if(root == key){
//		return 0;
//	}
//	
//	if(root == NULL){
//		return INT_MAX;
//	}
//	
//	int l1 = 1 + depth(root->left,key);
//	int l2 = 1 + depth(root->right,key);
//	
//	return min(l1,l2);
//	
//}
//
//
//int main(){
//	
//
//	return 0;
//}





void preorder(Node* root){
	if(root == NULL) return;
	
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node* root){
	if(root == NULL) return;
	
	
	preorder(root->left);
	cout<<root->data<<" ";
	preorder(root->right);
}


void postorder(Node* root){
	if(root == NULL) return;
	
	preorder(root->left);
	preorder(root->right);
	cout<<root->data<<" ";
	
}


//Level Order Traversal::


void levelOrder(Node* root){
	queue<Node*> q;
	q.push(root);
	
	while(!q.empty()){
		auto curr = q.front();
		q.pop();
		cout<<curr->data<<" ";
		if(curr->left) q.push(curr->left);
		if(curr->right) q.push(curr->right);
	}
}



















