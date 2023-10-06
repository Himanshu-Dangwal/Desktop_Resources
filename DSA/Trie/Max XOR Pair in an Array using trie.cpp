//Max XOR Pair in an array using trie::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

struct trienode{
	trienode* left;
	trienode* right;
};

void insert(trienode* head,int val){
	
	trienode* curr = head;
	
	for(int i=31;i>=0;i--){
		int b = (val >> i) & 1;
		
		if(b == 0){
			if(!curr->left){
				curr->left = new trienode();
			}
			curr = curr->left;
		}else{
			if(!curr->right){
				curr->right = new trienode();
			}
			curr = curr->right;
		}
	}
}


int max_XOR_Pair(int arr[],trienode* head,int n){
	
	int max_val = INT_MIN;
	for(int j=0;j<n;j++){
		trienode* curr = head;
		int val = arr[j];
		int curr_XOR = 0;
		for(int i=31;i>=0;i--){
			int bit = (val >> i) & 1;
			if(bit == 0){
				if(curr->right){
					curr = curr->right;
					curr_XOR += int(pow(2,i) + 0.5);
				}else{
					curr = curr->left;
				}
			}else{
				if(curr->left){
					curr = curr->left;
					curr_XOR += int(pow(2,i) + 0.5);
				}else{
					curr = curr->right;
				}
			}
		}
		max_val = max(max_val,curr_XOR);
	}
	return max_val;
	
}

int main(){
	int n;
	cin>>n;
	
	int arr[n];
	trienode* head = new trienode();
	for(int i=0;i<n;i++){
		cin>>arr[i];
		insert(head,arr[i]);
	}
	
	cout<<max_XOR_Pair(arr,head,n)<<endl;

	return 0;
}

