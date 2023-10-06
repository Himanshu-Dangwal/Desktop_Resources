#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int dp[n][m];
    
    int maxi = INT_MIN;
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i == n-1 || j == m-1){
                dp[i][j] = arr[i][j];
            }else{
                dp[i][j] = arr[i][j] == 0 ? 0 : min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1])) + 1;
            }
            
            maxi = max(dp[i][j],maxi);
        }
    }
    // cout<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    cout<<maxi;
    return 0;
}
