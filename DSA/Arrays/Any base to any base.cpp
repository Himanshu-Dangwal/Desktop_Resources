//Any base to any base::
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
	
	int base1;
	cin>>base1;
	
	int base2;
	cin>>base2;
	
	//base1 to decimal::

	int p = 1;
	int ans1 = 0;
	
	while(n != 0){
		int rem = n%10;
		ans1 += rem * p;
		p = p*base1;
		n /= 10;
	}
	cout<<"In decimal = "<<ans1<<endl;
	//1011 in base 2 -> base 8::
	//decimal to base2
	p=1;
	int ans2 = 0;
	
	while(ans1 != 0){
		int rem = ans1%base2;
		ans2 += rem * p;
		p = p*10;
		ans1 /= 8;
	}
	
	cout<<ans2<<endl;
	return 0;
}



