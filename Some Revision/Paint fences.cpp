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

	//Paint fences::
	
	int n,k;
	cin>>n>>k;
	
	//Given n >= 2::
	
	int l2s = k;
	int l2d = k*(k-1);
	int total = l2s + l2d;
	for(int i=3;i<=n;i++){
		l2s = l2d;
		l2d = total * (k-1);
		
		cout<<l2s<<" "<<l2d<<endl;
		
		total = l2s + l2d;
	}

	cout<<total<<endl;
	return 0;
}


