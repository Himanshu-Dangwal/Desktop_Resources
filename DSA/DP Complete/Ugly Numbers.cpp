//Ugly Numbers::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin>>n;
	
	int dp[n+1];
	dp[0] = 0;
	dp[1] = 1;
	
	int p2 = 1;
	int p3 = 1;
	int p5 = 1;
	
	for(int i=2;i<=n;i++){
		
		int val1 = 2 * dp[p2];
		int val2 = 3 * dp[p3];
		int val3 = 5 * dp[p5];
		
		int min_val = min(val1,min(val2,val3));
		
		dp[i] = min_val;
		
		if(min_val == val1){
			p2++;
		}
		if(min_val == val2){
			p3++;
		}
		
		if(min_val == val3){
			p5++;
		}
	}
	cout<<endl;
	cout<<dp[n]<<endl;

	return 0;
}

