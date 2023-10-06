#include<bits/stdc++.h>
using namespace std;

class trieNode{
  public:
    trieNode* left;
    trieNode* right;
    int val;
    
};

void insert(int val,trieNode* head){
    
    
    trieNode* curr = head;
    for(int i=31;i>=0;i--){
        int b = (val >> i) & 1;
        
        if(b == 0){
            if(!curr->left){
                curr->left = new trieNode();
            }
            curr = curr->left;    
        }else{
            if(!curr->right){
                curr->right = new trieNode();
            }
            curr = curr->right;
        }
    }
    curr->val = val;
}

int query(int val,trieNode* head){
    
    trieNode* curr = head;
    
    for(int i=31;i>=0;i--){
        int b = (val >> i) & 1;
        if(b == 0){
            if(curr->right){
                curr = curr->right;
            }else{
                curr = curr->left;
            }
        }else{
            if(curr->left){
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }
    }
    return val ^ curr->val;
}

int findMax_Xor_Subarray(int arr[],int n){
    trieNode* head = new trieNode();
    int preXOR = 0;
    int result = 0;
    insert(preXOR,head);
    for(int i=0;i<n;i++){
        preXOR = preXOR ^ arr[i];
        insert(preXOR,head);
        int pa = query(preXOR,head);
        result = max(result,pa);
    }
    
    return result;
}

int main() {

	int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    cout<<findMax_Xor_Subarray(arr,n);
}
