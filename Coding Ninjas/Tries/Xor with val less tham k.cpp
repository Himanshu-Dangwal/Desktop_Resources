#include <bits/stdc++.h>
using namespace std;
 
struct treeNode{
  	treeNode *left;
    treeNode *right;
    int rightCount = 0;
    int leftCount = 0;
};
 
void insert(int element,treeNode* head){
    treeNode *curr = head;
    for(int i=31;i>=0;i--){
        int b = (element>>i)&1;
        if(b==0){
            if(!curr->left){
                curr->left = new treeNode();
            }
            curr->leftCount += 1;
            curr=curr->left;
        }else{
            if(!curr->right){
                curr->right = new treeNode();
            }
            curr->rightCount += 1;
            curr = curr->right;
        }
    }
}
 
long long query(int element,int k,treeNode *head){
    treeNode *curr = head;
    long long count = 0;
    for(int i=31;i>=0;i--){
        int p = (element>>i)&1;
        int K = (k>>i)&1;
        if(p==1 && K==1){
            count+=curr->rightCount;
            if(curr->left) curr = curr->left;
            else break;
        }
        if(p==1 && K==0){
            if(curr->right) curr = curr->right;
            else break;
        }
        if(K==1 && p==0){
            count+=curr->leftCount;
            if(curr->right) curr = curr->right;
            else break;
        }
        if(K==0 && p==0){
            if(curr->left) curr = curr->left;
            else break;
        }
    }
    return count;
}
 
long long count_Less_Than_K(int *arr,int n,int k){
    treeNode *head = new treeNode();
    // insert(0,head);
    long long pre_xor = 0;
    long long count = 0;
    for(int i=0;i<n;i++){
        pre_xor = pre_xor ^ arr[i];
        count += query(pre_xor,k,head);
        insert(pre_xor,head);
        if(pre_xor < k) ++count;
    }
    return count;
}
 
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int *arr = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<count_Less_Than_K(arr,n,k)<<'\n';
    }
    return 0;
}
