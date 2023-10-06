#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	
	int e,f;
	cin>>e>>f;
	
	
	int dp[e+1][f+1];
	
	for(in i=0;i<=e;i++){
		
		for(int j=0;j<=f;j++){
			
			if(j == 0){
				dp[i][j] = 0;
			}
			else if(i == 0){
				dp[i][j] = NULL;
			}
			else if(i == 1){
				dp[i][j] = j;
			}else if(j == 1){
				dp[i][j] = 1;
			}else{
				int min_val = INT_MAX;
				
				for(int mj = j-1,prj = 0;mj >=0;mj--,prj++){
					
					int curr_max = max(dp[i][mj],dp[i-1][prj]);
					min_val = min(curr_max,min_val);
						
				}
			
				dp[i][j] = min_val + 1;
			}
			
		}
	
	}
	
	cout<<dp[e][f]<<endl;
	
	return 0;
}


