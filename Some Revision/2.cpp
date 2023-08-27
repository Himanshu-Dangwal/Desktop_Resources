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

	int n;
	cin>>n;
	
	vector<bool> sieve(n+1,true);
	sieve[0] = false;
	sieve[1] = false;
	
	for(int i=2;i*i<=n;i++){
		if(sieve[i]){
			
			for(int j=i*i;j<=n;j+=i){
				sieve[j] = false;
			}
		}
	}
	
	vector<int> primes;
	
	for(int i=0;i<=n;i++){
		if(sieve[i]){
			primes.push_back(i);
		}
	}
	
	
	int cnt = 0;
	
	for(int i=6;i<=n;i++){
		
		int curr = i;
		int j=0;
		int count = 0;
		while(curr){
			bool flag = false;
			while(curr%primes[j] == 0){
				flag = true;
				curr /= primes[j];
			}
			
			if(flag) count++;
			j++;
			
			if(curr == 1) break;
		}
		
		if(count == 2){
			cnt++;
		}
		
	}
	cout<<cnt;

	return 0;
}


