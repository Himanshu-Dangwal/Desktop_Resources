//Any base addition::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n1,n2;
	cin>>n1>>n2;
	
	int base;
	cin>>base;
	
	int p = 1;
	int ans = 0;
	int carry = 0;
	
	while(n1 != 0 || n2 != 0){
		int rem1 = n1%10;
		int rem2 = n2%10;
		
		int val = rem1 + rem2 + carry; 
		
		int last = val % base;
		ans += last * p;
		p = p * 10;
		
		carry = val/base;
		
		n1 /= 10;
		n2 /= 10;
	}
	
	if(carry){
		ans += p * carry;
	}
	
	cout<<ans<<endl;
	return 0;
}

