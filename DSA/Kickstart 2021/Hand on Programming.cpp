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
	
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	vector<int> count(n+1,0);
	
	for(int x : arr) count[x]++;
	
	int cnt = 0;
	for(int i=1;i<=n;i++){
		if(count[i] == 0){
			cnt++;
			for(int j=1;j<=n;j++){
				if(count[j] > 1) count[j]--;
				break;
			}
		}
	}
	
	cout<<cnt<<endl;

	return 0;
}


