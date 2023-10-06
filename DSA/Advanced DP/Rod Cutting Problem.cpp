#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int prices[n+1];
    
    for(int i=1;i<=n;i++){
        cin>>prices[i];
    }
    
    int dp[n+1];
    dp[0] = 0;
    dp[1] = prices[1];
    
    for(int i=2;i<=n;i++){
        dp[i] = prices[i];
        
        int li = 1;
        int ri = i-1;
        
        while(li <= ri){
            if(dp[li] + dp[ri] > dp[i]){
                dp[i] = dp[li] + dp[ri];
            }
            li++;
            ri--;
        }
    }
    cout<<dp[n]<<endl;
}
