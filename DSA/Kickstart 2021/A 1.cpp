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


void solve(int i){
	
	int n,k;
	string s;
	int ans;
	
	cin>>n>>k;
	cin>>s;
	
	int l = 0;
	int r = n-1;
	
	int cnt = 0;
	
	while(l <= r){
		if(s[l] != s[r]){
			cnt++;
		}
		
		l++;
		r--;
	}
	
	
	ans = abs(k-cnt);
	cout<<"Case #"<<i<<":"<<ans<<endl;
	
}


int main(){
	int t;
	cin>>t;
	int i=1;
	while(t--){
		solve(i);
		i++;
	}

	return 0;
}


