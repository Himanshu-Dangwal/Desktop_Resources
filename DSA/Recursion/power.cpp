#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int power(int x,int n){
	if(n==1){
		return x;
	}
	return x * power(x,n-1);
}

int main(){
	int x,n;
	cin>>x>>n;
	
	cout<<power(x,n)<<endl;

	return 0;
}

