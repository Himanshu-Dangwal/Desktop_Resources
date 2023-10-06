//Paint Houses Many Colours::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	
	int arr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	
	int dp[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			dp[i][j] = 0;
		}
	}
	int fm = INT_MAX;
	int sm = INT_MAX;
	for(int i=0;i<m;i++){
		if(arr[0][i] < fm){
			sm = fm;
			fm = arr[0][i];
		}else if(arr[0][i] < sm){
			sm = arr[0][i];
		}
		dp[0][i] = arr[0][i];
	}
	cout<<endl;
	cout<<"fm "<<fm<<" sm "<<sm<<endl;
	for(int i=1;i<n;i++){
		for(int j=0;j<m;j++){
			if(dp[i-1][j] != fm){
				dp[i][j] = arr[i][j] + fm;
			}else{
				dp[i][j] = arr[i][j] + sm;
			}
		}
		//Updating fm and sm::    fm = first minimum  &  sm = second minimum::
		fm = INT_MAX;
		sm = INT_MAX;
		for(int j=0;j<m;j++){
			if(dp[i][j] < fm){
				sm = fm;
				fm = dp[i][j];
			}else if(dp[i][j] < sm){
				sm = dp[i][j];
			} 
		}
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	int min_val = INT_MAX;
	for(int i=0;i<m;i++){
		if(dp[n-1][i] < min_val){
			min_val = dp[n-1][i];
		}
	}
	cout<<min_val<<endl;
	return 0;
}

