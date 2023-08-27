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

	int ans =0;
	
	ans = (5*500000004)%MOD;
	
//	ans = (ans + (1*(333333336)) %MOD)%MOD;
	
	
	ans =(ans + (5*(250000002))%MOD)%MOD;
	cout<<(ans+MOD)%MOD;
	return 0;
}


