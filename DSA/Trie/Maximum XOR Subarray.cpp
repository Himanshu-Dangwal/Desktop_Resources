/*
Maximum XOR Subarray
Send Feedback
Given an array of n integers, find subarray whose xor is maximum.
Input Format
First line contains single integer n (1<=n<=1000000).
Next line contains n space separated integers.
Output Format
Print xor of the subarray whose xor of all elements in subarray is maximum over all subarrays.
Constraints
1 <= n <= 1000000
1 <= A[i] <=100000 
Sample Input
4
1 2 3 4
Sample Output
7
*/



#include<bits/stdc++.h>
using namespace std;

struct treeNode{
    treeNode *left;
    treeNode *right;
    int val;
};

void insert(int val,treeNode *head){
    treeNode *curr = head;
    
    for(int i=31;i>=0;i--){
        int b = (val>>i)&1;
        if(b==0){
            if(!curr->left){
                curr->left = new treeNode();
            }
            curr = curr->left;
        }else{
            if(!curr->right){
                curr->right = new treeNode();
            }
            curr = curr->right;
        }
    }
    curr->val = val;
}

int query(int val,treeNode *head){
    treeNode *curr = head;
    for(int i=31;i>=0;i--){
        int b = (val>>i)&1;
        if(b==0){
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
    return val^curr->val;
}

int findMaxSubXor(int *arr,int n){
    treeNode *head = new treeNode();
    int pre_xor = 0;
    insert(pre_xor,head);
    int result = INT_MIN;
    for(int i=0;i<n;i++){
        pre_xor = pre_xor ^ arr[i];
        insert(pre_xor,head);
        result = max(result,query(pre_xor,head));
    }
    return result;
}

int main() {

	// Write your code here
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<findMaxSubXor(arr,n);
    return 0;
}
