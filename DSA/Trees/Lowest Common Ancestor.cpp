//Sum Replacement in a Binary Tree::
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

void levelOrderTraversal(Node* root){
	Node* temp = root;
	queue<Node*> q;
	q.push(temp);
	while(!q.empty()){
		Node* curr = q.front();
		q.pop();
		cout<<curr->data<<" ";
		if(curr->left != NULL)
			q.push(curr->left);
		if(curr->right != NULL)
			q.push(curr->right);
	}
}

void sumReplacement(Node *root){
	if(root == NULL)
		return;
	
	sumReplacement(root->left);
	sumReplacement(root->right);
	
	if(root->left != NULL){
		root->data += root->left->data;
	}
	if(root->right != NULL){
		root->data += root->right->data;
	}
}

bool getPath(Node* root,int key,vector<int>&path){
	if(root == NULL)
		return false;
	path.push_back(root->data);
	if(root->data == key){
		return true;
	}
	if(getPath(root->left,key,path) || getPath(root->right,key,path)){
		return true;
	}
	path.pop_back();
	return false;
}

Node* LCA2(Node *root,int n1,int n2){
	if(root == NULL){
		return NULL;
	}
	
	if(root->data == n1 || root->data == n2){
		return root;
	}
	
	Node* leftLCA = LCA2(root->left,n1,n2);
	Node* rightLCA = LCA2(root->right,n1,n2);
	
	if(leftLCA!=NULL && rightLCA!=NULL){
		return root;
	}
	
	if(leftLCA != NULL){
		return leftLCA;
	}
	return rightLCA;
}

int LCA(Node* root,int n1,int n2){          //Lowest Common Ancestor::
	
	vector<int> path1,path2;
	
	if(getPath(root,n1,path1) && getPath(root,n2,path2)){
		int pc;  //Path Change
		//Print path 1::
//		for(int i=0;i<path1.size();i++)
//			cout<<path1[i]<<" ";
//		cout<<endl;	
//		for(int i=0;i<path2.size();i++)
//			cout<<path2[i]<<" ";
//		cout<<endl;	
//		for(pc = 0;pc < (path1.size() && path2.size());pc++){
//			if(path1[pc] != path2[pc]){
//				return path1[pc-1];
//			}
//		}
		int s1 = path1.size();
		int s2 = path2.size();
//		cout<<s1<<" "<<s2<<endl;
		int val_min = min(s1,s2);
		int i;
		for(i=0;i<val_min;i++){
			if(path1[i] != path2[i]){
				return path1[i-1];
			}
		}
		if(i==val_min){
			return 	path1[i-1];
		}
	}else{
		return -1;
	}
}

int main(){
	struct Node* root = new Node(1);
	root->left = new Node(2);
//	cout<<"val";
	root->right = new Node(3);
	root->right->left = new Node(4);
	root->right->right = new Node(5);
//	root->right->left = new Node(6);
//	root->right->right->right = new Node(6);
//	sumReplacement(root);
	int n1,n2;
	cin>>n1>>n2;
	int lca = LCA(root,n1,n2);
	Node* newLca = LCA2(root,n1,n2);
	cout<<lca<<endl;
	cout<<newLca->data<<endl;
//	levelOrderTraversal(root);
//	int count = count_all_nodes(root);
//	cout<<count<<endl;
	return 0;
}

