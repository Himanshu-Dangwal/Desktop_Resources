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
		int data;
		
		Node(int val){
			data = val;
			left = NULL;
			right = NULL;
		}
};

void print_k_sum_paths(Node* root,int curr_sum,vector<int> &path,int k){
	if(root == NULL) return;
	
	curr_sum += root->data;
	path.push_back(root->data);

	if(root->left == NULL && root->right == NULL){
		if(curr_sum == k){
			for(int i=0;i<path.size();i++){
				cout<<path[i]<<" ";
			}
			path.pop_back();
			cout<<endl;
			return;
		}
	}

	print_k_sum_paths(root->left,curr_sum,path,k);
	print_k_sum_paths(root->right,curr_sum,path,k);
	path.pop_back();
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(2);
	int k = 21;
	vector<int> path;
	
	print_k_sum_paths(root,0,path,k);
	return 0;
}


