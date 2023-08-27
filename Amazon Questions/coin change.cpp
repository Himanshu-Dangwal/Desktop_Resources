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

//    4
//    {1,2,3}
//    
//    0   1   2   3  4
//    1   .   .   .  .
//                               1, 
//                               1,1,1
//                               1,2
//                               
//                               1,1,1,1
//                               1,1,2
//                               2,2
//                               
//                               
//                               2
//                               1,1
//                               
//   1   1   1   1  1
//    
//           2   2  3
//               
//               3  4
               
    


int coin_change(int sum,vector<int> &coins){
	
	vector<int> dp(sum+1,0);
	dp[0] = 1;
	
	for(int coin : coins){
		
		for(int i=coin;i<=sum;i++){
			dp[i] = dp[i] + dp[i-coin];
		}
		
	}
	
	return dp[sum];
	
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int sum;
	cin>>sum;
	
	
	vector<int> coins;
	for(int i=0;i<4;i++){
		int x;
		cin>>x;
		coins.push_back(x);
	}
	
	
	cout<<coin_change(sum,coins);

	return 0;
}


