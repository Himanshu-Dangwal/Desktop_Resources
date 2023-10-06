//Wildcard Pattern Matching::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	
	string pattern ,text;
	cin>>text>>pattern;
	
	int n = pattern.length();
	int m = text.length();
	
	bool dp[n+1][m+1];
	
	for(int i=n;i>=0;i--){
		for(int j=m;j>=0;j--){
			if(i==n && j==m){
				dp[i][j] = true;
			}
			else if(i==n){
				dp[i][j] = false;
			}
			else if(j==m){
				if(pattern[i] == '*'){
					dp[i][j] = dp[i+1][j];
				}else{
					dp[i][j] = false;
				}
			}
			else{
				if(pattern[i] == '*'){
					dp[i][j] = dp[i][j+1] || dp[i+1][j]; 
				}
				else if(pattern[i] == '?'){
					dp[i][j] = dp[i+1][j+1];
				}
				else{
					if(pattern[i] == text[j]){
						dp[i][j] = dp[i+1][j+1];
					}else{
						dp[i][j] = false;
					}
				}
			}
		}
	}
	
// 	for(int i=0;i<=n;i++){
// 		for(int j=0;j<=m;j++){
// 			cout<<dp[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}
	
    if(dp[0][0])
        cout<<"true";
    else
        cout<<"false";
	
	return 0;
}

