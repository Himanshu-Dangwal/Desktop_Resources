#include <bits/stdc++.h>
using namespace std;
#define int long long

class trieNode{
  public:
    trieNode* left;
    trieNode* right;
    int leftCount = 0;
    int rightCount = 0;
};

void insert(int val,trieNode* head){
    trieNode* curr = head;
    
    for(int i=31;i>=0;i--){
        int bit = (val >> i) & 1;
        
        if(bit == 0){
            if(!curr->left){
                curr->left = new trieNode();
            }
            curr->leftCount += 1;
            curr = curr->left;
        }else{
            if(!curr->right){
                curr->right = new trieNode();
            }
            curr->rightCount += 1;
            curr = curr->right;
        }
    }
}

int query(int val,trieNode* head,int k){
    trieNode* curr = head;
    int count = 0;
    for(int i=31;i>=0;i--){
        int p = (val >> i) & 1;
        int K = (k >> i) & 1;
        
        if(p == 1 && K == 1){
            count += curr->rightCount;
            if(curr->left) curr = curr->left;
            else break;
        }else if(p == 1 && K == 0){
            if(curr->right) curr = curr->right;
            else break;
        }else if(p == 0 && K == 0){
            if(curr->left) curr = curr->left;
            else break;
        }else{
            count += curr->leftCount;
            if(curr->right) curr = curr->right;
            else break;
        }
    }
    return count;
}

int subXOR(int arr[],int n,int k){
    trieNode* head = new trieNode();
    int preXOR = 0;
    int count = 0;
    
    for(int i=0;i<n;i++){
        preXOR = preXOR ^ arr[i];
        count += query(preXOR,head,k);
        insert(preXOR,head);
        if(preXOR < k){
            count++;
        }
    }
    return count;
}

signed main()
{
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        
        int arr[n];
        for(int i=0;i<n;cin>>arr[i++]);
        
        cout<<subXOR(arr,n,k)<<endl;
    }
    return 0;
}

