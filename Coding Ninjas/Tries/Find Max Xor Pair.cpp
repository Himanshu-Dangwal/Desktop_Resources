////Tries:::
//
//// Find Maximum XOR in a given array:: 
//#include<bits/stdc++.h>
//using namespace std;
//
//struct trieNode{
//	trieNode *left;
//	trieNode *right;
//};
//
//void insert(int a,trieNode *head){
//	trieNode *curr = head;
//	for(int i=31;i>=0;i--){
//		int b = (a>>i)&1;
//		if(b==0){
//			if(!curr->left){
//				curr->left = new trieNode();
//			}
//			curr = curr->left;
//		}else{
//			if(!curr->right){
//				curr->right = new trieNode();
//			}
//			curr = curr->right;
//		}
//	}
//	return;
//}
//
//int findMaxXor(int *arr,trieNode *head,int n){
//	int max_xor = INT_MIN;
//	for(int i=0;i<n;i++){
//		int curr_xor = 0;
//		int element = arr[i];
//		trieNode *curr = head;
//		for(int i=31;i>=0;i--){
//			
//			int b = (element>>i)&1;
//			if(b==0){
//				if(curr->right){
//					curr_xor+=pow(2,i);
//					curr = curr->right;
//				}else{
//					curr = curr->left;
//				}
//			}else{
//				if(curr->left){
//					curr_xor+=pow(2,i);
//					curr = curr->left;
//				}else{
//					curr = curr->right;
//				}
//			}
//		}
//		if(curr_xor > max_xor){
//			max_xor = curr_xor;
//		}
//	}
//	return max_xor;
//}
//
//int main(){
//	int n;
//	cin>>n;
//	trieNode *head = new trieNode();
//	int *arr = new int[n];
//	for(int i=0;i<n;i++){
//		cin>>arr[i];
//	}
//	for(int i=0;i<n;i++){
//		insert(arr[i],head);
//	}
//	cout<<findMaxXor(arr,head,n);
//	return 0;
//}






#include<bits/stdc++.h>
using namespace std;

class trienode{
	public:
		trienode *left;
		trienode *right;
};

void insert(trienode *head,int val){
	trienode* curr = head;
	for(int i=31;i>=0;i--){
		int curr_bit = (val>>i)&1;
		if(curr_bit == 1){
			if(!curr->right){
				curr->right = new trienode();
			}
			curr = curr->right;
		}else{
			if(!curr->left){
				curr->left = new trienode();
			}
			curr = curr->left;
		}
	}
}

int find(int val,trienode *head){
	trienode *curr = head;
	int ans = 0;
	for(int i=31;i>=0;i--){
		int curr_bit = (val>>i)&1;
		if(curr_bit == 0){
			if(curr->right){
				ans += (int)(pow(2,i)+ 0.5);
				curr = curr->right;
			}else{
				curr = curr->left;
			}
		}else{
			if(curr->left){
				ans += (int)(pow(2,i) + 0.5);
				curr = curr->left;
			}else{
				curr = curr->right;
			}
		}
	}
}

int main(){
	int n;
	cin>>n;
	trienode* head = new trienode();
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}	
	for(int i=0;i<n;i++){
		insert(head,arr[i]);
	}
	for(int i=0;i<n;i++){
		int val = find(arr[i],head);
		if(val > max_xor){
			max_xor = value;
		}
	}
	cout<<max_xor<<endl;
}







