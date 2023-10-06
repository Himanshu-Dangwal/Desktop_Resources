#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.length();
    bool dp[n][n];
    
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;i++,j++){
            if(g == 0){
                dp[i][j] = true;
            }else if(g == 1){
                if(s[i] == s[j]){
                    dp[i][j] = true;
                }else{
                    dp[i][j] = false;
                }
            }else{
                if(s[i] == s[j]){
                    if(dp[i+1][j-1]){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = false;
                    }
                }else{
                    dp[i][j] = false;
                }
            }
        }
    }
    
    int strg[n][n];
    
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;i++,j++){
            if(g == 0){
                strg[i][j] = 0;
            }else if(g == 1){
                if(s[i] != s[j]){
                    strg[i][j] = 1;
                }else{
                    strg[i][j] = 0;
                }
            }else{
                if(dp[i][j]){
                	strg[i][j] = 0;
				}else{
					int min = INT_MAX;
	                
	                for(int k=i;k<j;k++){
	                    int lc = strg[i][k];
	                    int rc = strg[k+1][j];
	                    
	                    if(lc + rc < min){
	                        min = lc + rc;
	                    }
	                    
	                }
	                
	                strg[i][j] = min + 1;
				}   
            }
        }
    }
    cout<<strg[0][n-1];
}












