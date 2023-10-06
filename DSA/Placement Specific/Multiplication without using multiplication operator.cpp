#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	int a,b;
	cin>>a>>b;
	
	int ans = 0;
	
	if(a < 0 && b<0){
		a = -a;
		b = -b;
	}
	else if(b < 0){
		int temp = b;
		b = a;
		a = temp;
	}
		
	while(b!=0){
		if(b == 1){
			ans += (a);
			break;
		}
		
		if(b&1){
			//Odd
			ans += a;
			a = a<<1;
			b = b>>1;
		}else{
			a = a<<1;
			b = b>>1;
		}
	}
	
	if(a<0 && b < 0)
		ans = abs(ans);
	cout<<ans<<endl;	
	return 0;
}

