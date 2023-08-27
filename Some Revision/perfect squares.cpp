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

	int n;
	cin>>n;
	
	vector<int> dp(n+1,INT_MAX);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	
	//Given n >= 4
	
	for(int i=4;i<=n;i++){
		for(int j=1;j*j <= i;j++){
			dp[i] = min(dp[i],1+dp[i-j*j]);
		}
	}
	
	cout<<dp[n]<<endl;


	return 0;
}


