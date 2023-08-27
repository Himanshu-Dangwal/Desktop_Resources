
//Preorder :   
//  40 30 35 80 100


// O/P:
//Postorder - > 35 30 100 80 40


//Inorder  30 35 40 80 100
//Preorder 40 30 35 80 100

/*

T.C - > O(n) * O(n)      S.C - > O(n) + O(n)
Step 1 : BST from preorder and inorder 
Step 2 : Postorder of the BST

Postorder from Inorder

root->val  = 40
root->left = 30 35 80 100    (min,max)  - > (INT_MIN,40)
root->right = 80 100         (40,INT_MAX) 

cout<<val

*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int ,  null_type ,  less<int>,  rb_tree_tag ,  tree_order_statistics_node_update>


//   order_of_key(x)   Number of items strictrly less than x
//   find_by_order(x)  Find the kth largest element(countingg from zero)


class Node{
	public:
		Node* left;
		Node* right;
		int value;
		
		Node(int x){
			value = x;
			left = right = NULL;
		}
};

Node* findPostOrder(vector<int> &preOrder,vector<int> &inOrder,int &preOrderIdx,int low,int high,int n){
	if(high < low) return NULL;
	
	if(preOrderIdx >= n) return NULL;
	if(preOrderIdx < 0) return NULL;
	int curr = preOrder[preOrderIdx];
	Node* root = new Node(curr);
	
	int idxInInorder = lower_bound(inOrder.begin(),inOrder.end(),curr) - inOrder.begin();
	cout<<idxInInorder<<endl;
	preOrderIdx++;
	if(preOrderIdx < n)
		root->left = findPostOrder(preOrder,inOrder,preOrderIdx,low,idxInInorder-1,n);
	if(preOrderIdx < n)
		root->right = findPostOrder(preOrder,inOrder,preOrderIdx,idxInInorder+1,high,n);
	return root;
}

void postOrder(Node* root){
	if(root == NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->value<<" ";
}

void preOrder(Node* &root){
	if(root == NULL) return;
	cout<<root->value<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

void findPostOrder2(vector<int> &preOrder,int n,int &preOrderIdx,int min_val,int max_val){
	if(preOrderIdx >= n) return;

	
	int curr = preOrder[preOrderIdx];

	if(curr < min_val || curr > max_val){
		return;
	}
	preOrderIdx++;
	
	findPostOrder2(preOrder,n,preOrderIdx,min_val,curr);
	findPostOrder2(preOrder,n,preOrderIdx,curr,max_val);
	
	cout<<curr<<" ";
		
}

int main(){
	int n;
	cin>>n;
	
	vector<int> preOrder,inOrder;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		preOrder.push_back(x);
		inOrder.push_back(x);
	}
	//Method 1 ::
//	sort(inOrder.begin(),inOrder.end());
//	int preOrderIdx = 0;
//	Node* root = findPostOrder(preOrder,inOrder,preOrderIdx,0,n,n);	

//	preOrder(root);
//	postOrder(root);


	//Method 2 ::
	int preOrderIdx = 0;
	findPostOrder2(preOrder,n,preOrderIdx,INT_MIN,INT_MAX);
	

	return 0;
}


