//Power of a  number on log2n time::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

double power(double x,int n){
	ll nn;
	nn = n;
	
	if(n < 0){
		nn = -1 * nn;
	}
	double ans = 1.0;
	while(nn){
		if(nn % 2 == 0){  //even power
			x = x * x;
			nn /= 2;
		}else{
			ans = ans * x;
			nn = nn - 1;
		}
	}
	
	if(n < 0){
		return ((double)1.0/ans);
	}
	
	return ans;
}


int main(){
	double x;
	int n;
	
	cin>>x>>n;
	
	cout<<power(x,n);
	return 0;
}

