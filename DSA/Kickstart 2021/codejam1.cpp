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
	int t;
	cin>>t;
	int c = 1;
	while(t--){
		int N;
		cin>>N;
		
		int n= 2*N;
		vector<vector<char>> arr(n,vector<char>(n));
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>arr[i][j];
			}
		}
		
		int cnt1 = 0,cnt2 = 0;
		int cnt3 = 0,cnt4 = 0;
		for(int i=0;i<N;i++){
			for(int j=0;j<n;j++){
				if(arr[i][j] == 'I') cnt1++;
			}
		}
		
		for(int i=N;i<n;i++){
			for(int j=0;j<n;j++){
				if(arr[i][j] == 'I') cnt2++;
			}
		}
		
		for(int i=0;i<N;i++){
			for(int j=0;j<n;j++){
				if(arr[i][j] == 'I') cnt3++;
			}
		}
		
		for(int i=N;i<n;i++){
			for(int j=0;j<n;j++){
				if(arr[i][j] == 'I') cnt4++;
			}
		}
		
		int val1 = abs(cnt1-cnt2);
		int val2 = abs(cnt3-cnt4);
		
		int ans = max(val1,val2);
		
		cout<<"Case #"<<c<<": "<<ans<<endl;
		
		c++;
	}

	return 0;
}


