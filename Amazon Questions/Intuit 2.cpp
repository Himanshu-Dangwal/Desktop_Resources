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
	
	int n,m;
	cin>>n>>m;
	
	vector<int> arr;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		
		arr.push_back(x);
	}
	
	int q;
	cin>>q;
	
	while(q--){
		
		int type;
		cin>>type;
		
		if(type == 1){
			int index,value;
			cin>>index>>value;
			index--;
			
			arr[index] = value;
		}else{
			int val;
			cin>>val;
			int cnt = 0;
			for(int i=0;i<n;i++){
				if(arr[i]%m == val){
					cnt++;
				}
			}
			
			cout<<cnt<<endl;
		}
		
	}



	return 0;
}


