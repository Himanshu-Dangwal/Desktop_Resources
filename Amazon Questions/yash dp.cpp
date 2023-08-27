#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int ,  null_type ,  less<int>,  rb_tree_tag ,  tree_order_statistics_node_update>


//   order_of_key(x)   Number of items strictrly less than x
//   find_by_order(x)  Find the kth largest element(countingg from zero)


int solve(vector<vector<char>> &arr,int i,int j,bool right,vector<vector<int>> &dp){
	int n = arr.size();
	int m = arr[0].size();
//	
//	if(dp[i][j] != -1){
//		return dp[i][j];
//	}
//	
	if(i >= n || j >=m || arr[i][j] == 'X' || j < 0 || i < 0){
		return 0;
	}
	
	//Collect the current and move right
	if(right){
		int option1 = (arr[i][j]-'0') + solve(arr,i,j+1,true,dp);
		
		
		
		int option2 = 0;
		if(i+1 < n && arr[i+1][j] != 'X'){
			if(j-1 >=0 && arr[i+1][j-1] != 'X'){
				option2 = (arr[i][j]-'0') + solve(arr,i+1,j-1,false,dp);
			}
		}
		return max(option1,option2);
	}else{
		int option1 = (arr[i][j]-'0') + solve(arr,i,j-1,true,dp);
		int option2 = 0;
		if(i+1 < n && arr[i+1][j] != 'X'){
			if(j+1 < m && arr[i+1][j+1] != 'X'){
				option2 = (arr[i][j] -'0') + solve(arr,i+1,j+1,true,dp);
			}
		}
		return max(option1,option2);
	}
	return 0;	
}

int main(){
	
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		
		vector<vector<char>> arr(n,vector<char>(m,'X'));
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>arr[i][j];
			}
		}
		
//		vector<vector<int>> dp(n,vector<int>(m,-1));
//	
//		for(int i=0;i<n;i++){
//			for(int j=0;j<m;j++){
//				cout<<dp[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		cout<<solve(arr,0,0,true,dp)<<endl;
	}


	return 0;
}


