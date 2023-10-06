//Any base to decimal

// (1172)8 -> base 10 

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	
	int base;
	cin>>base;
	
	int ans = 0;
	int p = 1;
	
	while(n != 0){
		int rem = n%10;
		ans += rem * p;
		n /= 10;
		p = p*base;
	}
	cout<<ans<<endl;
	return 0;
}

