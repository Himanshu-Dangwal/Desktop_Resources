#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;cin>>arr[i++]);
    
    int dp[n];
    dp[0] = 1;
    int res = 1;
    for(int i=1;i<n;i++){
        int maxi = 0;
        for(int j=i-1;j>=0;j--){
            if(arr[j] < arr[i]){
                maxi = max(maxi,dp[j]);
            }
        }
        dp[i] = maxi + 1;
        res = max(res,dp[i]);
    }
    cout<<endl;
    for(int i=0;i<n;i++){
    	cout<<dp[i]<<" ";
	}
    cout<<endl;
    cout<<res;
    return 0;
}
