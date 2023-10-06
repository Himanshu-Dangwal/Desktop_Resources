#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int ,  null_type ,  less<int>,  rb_tree_tag ,  tree_order_statistics_node_update>


//   order_of_key(x)   Number of items strictrly less than x
//   find_by_order(x)  Find the kth largest element(countingg from zero)

typedef long long ll;
ll findMax(vector<int> &nums){
	int n = nums.size();
	
	ll xoro = 0;
	
	for(int x : nums) xoro ^= x;
	ll ans = 0;

	if(n%2){
		ans += (n-1)*(33554431);
		ans += xoro;
		return ans;
	}else{
		ans += (n-2)*(33554431);
		
		ll val1 = 0,val2=0;
		
		for(int i=1;i<=25;i++){
			if(((xoro>>(i-1))&1) == 0){
				//Unset
				//Set (i-1)th bit in both numbers as 1;
				
				val1 = val1 | (1<<(i-1));
				val2 = val2 | (1<<(i-1));
				
				cout<<"here"<<endl;
			}else{
				//Set
				//Set (i-1)th bit in val1 as 1;
				val1 = val1 | (1<<(i-1));
			}
		}
		return ans+val1+val2;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	
	vector<int> nums(n);
	
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	
	cout<<findMax(nums);

	return 0;
}


