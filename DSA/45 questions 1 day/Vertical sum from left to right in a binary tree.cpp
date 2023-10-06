//Top View Of a Binary tree::

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
#define PII pair<Node*,int>

struct Node{
	int data;
	Node* left;
	Node* right;
	
	Node(int val){
		data = val;
		left = right = NULL;
	}
};


vector<int> topView(Node* root){
	queue<PII> q;
	q.push(make_pair(root,0));
	map<int,int> m;
	
	while(!q.empty()){
		auto it = q.front();
		q.pop();
		
		if(m.find(it.second) == m.end()){
			m[it.second] = it.first->data;
		}else{
			m[it.second] += it.first->data;
		}
		
		if(it.first->left != NULL){
			q.push(make_pair(it.first->left,it.second - 1));
		}
		
		if(it.first->right != NULL){
			q.push(make_pair(it.first->right,it.second + 1));
		}
		
	}
	
	vector<int> ans;
	
	for(auto it : m){
		ans.push_back(it.second);
	}
	
	return ans;
	
}

int main(){
	
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left= new Node(4);
	root->left->right = new Node(5);
	root->left->right->left = new Node(6);
	root->right->right = new Node(7);
	root->left->left->left = new Node(8);
	
	vector<int> ans = topView(root);
	
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}

	return 0;
}

