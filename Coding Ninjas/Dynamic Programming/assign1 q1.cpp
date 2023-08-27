#include<bits/stdc++.h>
int max_loot(int *arr,int size,int *dp,int n){
    if(size<=0){
        return 0;
    }
    if(size==1){
        return arr[0];
    }
    if(dp[n-size] > -1){
        return dp[n-size];
    }
    int option1 = max_loot(arr+1,size-1,dp,n);
    int option2 = max_loot(arr+2,size-2,dp,n);
    option2 = option2 + arr[0];
    int x= max(option1,option2);
    dp[n-size] = x;
    return x;
}

int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
  
    int size = n;
    int *dp = new int[n];
    memset(dp,-1,sizeof(dp));
    int k = max_loot(arr,n,dp,size);
    return k;
}
