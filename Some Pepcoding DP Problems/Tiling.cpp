//Tiling with 2*1 dominos on a 2*n floor::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	int n;
	cin>>n;
	
	int a = 1;  //for n=1
	int b = 2;  //for n=2
	
	int ans = 0;
	
	for(int i=3;i<=n;i++){
		ans = a + b;
		a = b;
		b = ans;
	}
	
	cout<<ans<<endl;

	return 0;
}

