//Grid Unique Paths::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

//Brute Using backtracking::
/*
int getPaths(int si,int sj,int ei,int ej){
	if(si == ei || sj == ej){
		return 0;
	}
	
	if(si == ei-1 && sj == ej-1){
		return 1;
	}
	
	return getPaths(si,sj+1,ei,ej) + getPaths(si+1,sj,ei,ej);
}
*/

//Optimal Using DP
/*
int main(){
	int n,m;
	cin>>n>>m;
	
	int dp[n][m];
	
	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=0;j--){
			if(i == n-1 || j == m-1){
				dp[i][j] = 1;
			}else{
				dp[i][j] = dp[i+1][j] + dp[i][j+1];
			}
		}
	}

	cout<<dp[0][0]<<endl;
	return 0;
}
*/


//The most optimal solution uses mathematics::


int main(){
	int n,m;
	cin>>n>>m;
	
	int steps = m + n - 2 ;
	
	int choice = m > n ? n-1 : m-1;
	//ans = steps C choice;   C -> Combination
	int result = 1;
	for(int i=1;i<=choice;i++){
		result *= (steps - choice + i)/i;
	}
	cout<<result<<endl;
	return 0;	
}
	














