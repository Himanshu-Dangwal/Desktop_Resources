#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.length();
    int dp[n+1][n+1];
    
    for(int i=n;i>=0;i--){
        for(int j=n;j>=0;j--){
            if(i==n && j==n){
                dp[i][j] = 0;
            }else if(i == n){
            	dp[i][j] = 0;
			}else if(j == n){
				dp[i][j] = 0;
			}else{
                if(s[i] == s[j] && i!=j){
                    dp[i][j] = dp[i+1][j+1] + 1;
                }else{
                    dp[i][j] = max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
    }
    
    
    for(int i=0;i<=n;i++){
    	for(int j=0;j<=n;j++){
    		cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
    
    cout<<dp[0][0];
    return 0;
}
