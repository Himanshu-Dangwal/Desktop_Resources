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
	int exp;
	cin>>exp;
	
	vector<int> power(n);
	vector<int> bonus(n);
	
	for(int i=0;i<n;i++){
		cin>>power[i];
	}
	
	for(int i=0;i<n;i++){
		cin>>bonus[i];
	}
	
	vector<pair<int,int>> vp;
	
	for(int i=0;i<n;i++){
		vp.push_back({power[i],bonus[i]});
	}
	
	sort(vp.begin(),vp.end());
	int cnt = 0;
	for(int i=0;i<vp.size();i++){
		if(vp[i].first < exp){
			exp+=vp[i].second;
			cnt++;
		}
	}
	
	cout<<cnt;

	return 0;
}


