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
//   find_by_order(x)  Number of items strictly less than x


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string a = "ababz";
	string b = "abz";
	
	
	string ans = min(a,b);
	cout<<ans;
	
	if(a > b) cout<<"True";
	else cout<<"False";
	
	return 0;
}

