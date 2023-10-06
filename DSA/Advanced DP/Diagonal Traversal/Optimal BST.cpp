#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int freq[n];
    for(int i=0;i<n;i++){
        cin>>freq[i];
    }
    
    int dp[n][n];
    
    vector<int> prefix(n,0);
    prefix[0] = freq[0];
    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1] + freq[i];
    }
    
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;i++,j++){
            if(g == 0){
                dp[i][j] = freq[i];
            }else if(g == 1){
                dp[i][j] = min(freq[i] + 2*freq[j],freq[j] + 2*freq[i]);
            }else{
                int mini = INT_MAX;
                
                for(int k=i;k<=j;k++){
                    int lc = k == i ? 0 : dp[i][k-1];
                    int rc = k == j ? 0 : dp[k+1][j];
                    
                    int tc = lc + rc;
                    if(tc < mini) mini = tc;
                }
                
                dp[i][j] = mini + prefix[j];
                if(i > 0) dp[i][j] -= prefix[i-1];
            }
        }
    }
    
    cout<<dp[0][n-1];
    return 0;
    
}
