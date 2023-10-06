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

 long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        long long res = 0;
        ordered_set finder;
        
        int n = nums1.size();
        
        vector<int> indices(nums1.size());
        for (int i = 0; i < nums2.size(); ++i)
        {
            indices[nums2[i]] = i;
        }

        vector<long long> pre(n),suff(n);
        
        for(int i=0;i<n;i++){
            int curr_pos = indices[nums1[i]];
            pre[i] = finder.order_of_key(curr_pos);
            finder.insert(curr_pos);
        }
        
        finder.clear();
        
        for(int i=n-1;i>=0;i--){
            int curr_pos = indices[nums1[i]];
            suff[i] = finder.size() - finder.order_of_key(curr_pos);
            finder.insert(curr_pos);
        }
        
        for(int i=0;i<n;i++){
            res += pre[i]*suff[i];
        }
        
        return res;
    }


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int n;
	cin>>n;
	
	
	vector<int> nums1(n),nums2(n);
	
	for(int i=0;i<n;i++){
		cin>>nums1[i];
	}
	
		
	for(int i=0;i<n;i++){
		cin>>nums2[i];
	}
	
	
	cout<<goodTriplets(nums1,nums2)<<endl;
	
	return 0;
}

