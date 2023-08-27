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

	int n,k;
	cin>>n>>k;
	
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	
	priority_queue<int>pq; //Max Heap:
	
	for(int i=0;i<n;i++){
		if(pq.empty()) pq.push(arr[i]);
		else{
			if(pq.size() < k){
				pq.push(arr[i]);
			}else{
				if(arr[i] < pq.top()){
					pq.pop();
					pq.push(arr[i]);
				}
			}
		}
	}
	
	cout<<pq.top();
	
	
	

	return 0;
}


