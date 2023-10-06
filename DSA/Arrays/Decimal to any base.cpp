//Decimal to any base::

// (634)10 -> base b

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
	
	int p = 1;
	int ans = 0;
	
	while(n != 0){
		int rem = n%8;
		ans += rem*p;
		p = p*10;	
		n /= 8;
	}
	
	cout<<ans<<endl;
	return 0;
}

