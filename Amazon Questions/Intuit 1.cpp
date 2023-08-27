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

int solve(vector<int> &arr){
	int n = arr.size();
	int ans = INT_MIN;
	for(int i=0;i<n;i++){
		int j;
		int mini = arr[i];
		for(j=i+1;j<n;j++){
			if(abs(arr[j]-mini) >= 2){
				break;
			}
			mini = min(mini,arr[j]);
		}	
		ans = max(ans,j-i);
	}
	
	return ans;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		
		vector<int> arr;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			arr.push_back(x);
		}
		cout<<solve(arr)<<endl;
	}


	return 0;
}


