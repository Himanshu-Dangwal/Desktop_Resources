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
	
	vector<ll> arr;
	
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		arr.push_back(x);
	}
	
	
	vector<pair<ll,int>> vp,ori;
	
	for(int i=0;i<n;i++){
		vp.push_back({arr[i],i});
		ori.push_back({arr[i],i});
	}
	ll good = 0;
	ll bad = 0;
	
	sort(vp.begin(),vp.end());
	
	for(int i=0;i<n;i++){
		if(vp[i].first == ori[i].first && vp[i].second == ori[i].second){
			good += vp[i].first;
		}else{
			bad += vp[i].first;
		}
	}
	
	ll ans = good - bad;
	cout<<ans<<endl;

	return 0;
}


