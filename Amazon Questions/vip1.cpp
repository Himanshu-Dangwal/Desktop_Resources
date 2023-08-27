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

int minimumMemory(vector<int> &arr,int m){
	
	int sum = 0;
	for(int x : arr) sum += x;
	
	priority_queue<int> pq;
	int curr = 0;
	for(int i=0;i<m;i++){
		curr += arr[i];
	}
	
	pq.push(curr);
	
	for(int i=m;i<arr.size();i++){
		curr += arr[i];
		curr -= arr[i-m];
		pq.push(curr);
	}
	
	sum -= pq.top();
	return sum;
	
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr.push_back(x);
	}

	int m;
	cin>>m;
	
	cout<<minimumMemory(arr,m);

	return 0;
}


