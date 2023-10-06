//Right View Of A Binary Tree::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
vector<int> rightView;
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

//bool isBalanced(Node *root){
//	if(root == NULL)
//		return true;
//	if(!isBalanced(root->left)){
//		return false;
//	}
//	
//	if(!isBalanced(root->right)){
//		return false;
//	}
//	
//	int lh = getHeight(root->left);
//	int rh = getHeight(root->right);
//	
//	if(abs(lh - rh) <=1 ){
//		return true;
//	}
//	return false;
//}

bool isBalanced(Node *root,int *height){
//	cout<<"inside it"<<endl;
	if(root == NULL){
//		*height = 0;
//		cout<<"Base Hits"<<endl;
		return true;	
	}
	
	int lh = 0;
	int rh = 0;
	
	if(isBalanced(root->left,&lh) == false)
		return false;
	if(isBalanced(root->right,&rh) == false) 
		return false;
		
	*height = max(lh,rh) + 1;
//	cout<<*height<<" ";
	if(abs(lh - rh) <= 1)
		return true;
	return false;			
}

void RightView(Node *root){
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
//	rightView.push_back(root->data);
	Node* prev = NULL;
	Node* current = NULL;
	while(!q.empty()){
		current = q.front();
		q.pop();
		
		if(current != NULL){
			if(current->left != NULL){
				q.push(current->left);
			}
			if(current->right != NULL){
				q.push(current->right);
			}
		}else{
			rightView.push_back(prev->data);
			if(!q.empty())
				q.push(NULL);
		}
		prev = current;
		
	}
}

int main(){
	struct Node* root = new Node(1);
	root->left = new Node(2);
//	cout<<"val";
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->right->left->left = new Node(8);
//	root->left->left = new Node(8);
	RightView(root);
	for(int i=0;i<rightView.size();i++){
		cout<<rightView[i]<<" ";
	}
	cout<<endl;
}

