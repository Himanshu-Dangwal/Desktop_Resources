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
	
	//Break n into its contituent primes::
	vector<bool> sieve(n+1,true);
	
	for(int i=2;i<=sqrt(n);i++){
		if(sieve[i]){
			for(int j=i*i;j<=n;j+=i){
				sieve[j] = false;
			}	
		}
	}
	cout<<"HEre"<<endl;
	vector<int> primes;
	
	for(int i=2;i<=n;i++){
		if(sieve[i]){
			primes.push_back(i);
		}
	}
	
	for(int i=0;i<primes.size();i++)
		cout<<primes[i]<<" ";	
	
	cout<<endl;
	int i = 0;
	int ans = 0;
	while(n > 0){
		
		bool flag = false;
		while(n%primes[i] == 0 && n != 0){
			
			ans += primes[i];
			n = n/primes[i];
		}

		
		i++;
		
		if(n == 1){
			break;
		}
	}
	

	
	cout<<ans<<endl;

	return 0;
}


