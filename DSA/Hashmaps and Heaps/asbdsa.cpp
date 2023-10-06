#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin>>s;
	
	int n = s.length();
	
	int dp[n][n];
	
	int count = 0;
	
	for(int g=0;g<n;g++){
		for(int i=0;j=g;j<n;i++,j++){
			
			if(g==0){
				dp[i][j] = 1;
			}else if(g == 1){
				
				if(s[i] == s[j]){
					dp[i][j] = 1;
				}else{
					dp[i][j] = 0;
				}
				
			}else{
				
				if(s[i] == s[j]){
					if(dp[i+1][j=1] == 1){
						dp[i][j] = 1;
					}else{
						dp[i][j] = 0;
					}
				}else{
					dp[i][j] = 0;
				}
				
			}
			
			if(dp[i][j] == 1){
				count++:
			}
			
		}
	}
	
	cout<<count<<endl;

	return 0;
}

