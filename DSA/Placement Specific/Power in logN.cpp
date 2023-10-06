
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	long long x,n;
	cin>>x>>n;
	
	bool flag = false; //for negative n::
	if(n < 0){
		n =0-n;
		flag = true;
	}
	
	float ans = 1;
	while(n != 0){
		if(n&1){
			ans *= x;	
		}
		x = x*x;
		n = n>>1;
	}
	if(flag){
		ans =(1.0/(float)ans);	
	}
	
	cout<<ans;
	return 0;
}

