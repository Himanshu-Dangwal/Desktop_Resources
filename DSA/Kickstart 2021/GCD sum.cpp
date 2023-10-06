#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
#define MAX 1e7
typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int ,  null_type ,  less<int>,  rb_tree_tag ,  tree_order_statistics_node_update>


//   order_of_key(x)   Number of items strictrly less than x
//   find_by_order(x)  Find the kth largest element(countingg from zero)



vector<int> phi(MAX);

void preProcessing(){
	
	for(int i=0;i<MAX;i++) phi[i] = i;
	
	for(int i=2;i*i < MAX;i++){
		if(phi[i] == i){
			phi[i] = i-1;
			for(int j = i*2;j<MAX;j+=i){
				phi[j] *= (i-1);
				phi[j] /= i;
			}	
		}
	}
	
}

int getCount(int a,int n){
	return phi[n/a];
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	preProcessing();

	int n;
	cin>>n;
	
//	cout<<phi[n]<<endl;
	// summation of gcd(i,n) from i = 1 to i= n:::
	int cnt = 0;
	
	for(int i=1;i*i <=n;i++){
		if(n%i == 0){
			int d1 = i;
			int d2 = n/i;

			cnt += d1 * getCount(d1,n);
		
			if(d1 != d2) cnt += d2*getCount(d2,n);
			
		}
	}
	
	cout<<cnt;
	return 0;
}


