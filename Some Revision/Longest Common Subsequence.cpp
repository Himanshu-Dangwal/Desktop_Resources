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


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s,p;
	cin>>s>>p;
	
	int n = s.length();
	int m = p.length();
	
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));

	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=0;j--){
			if(s[i] == p[j]){
				dp[i][j] = dp[i+1][j+1] + 1;
			}else{
				dp[i][j] = max(dp[i][j+1],dp[i+1][j]);
			}
		}
	}
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	cout<<dp[0][0]<<endl;


	return 0;
}


