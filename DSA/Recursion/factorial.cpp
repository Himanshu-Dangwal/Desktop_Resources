#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int factorial(int n){
	
	if(n==1){
		return 1;
	}
	
	return n*factorial(n-1);
}


int main(){
	int n;
	cin>>n;
	
	cout<<factorial(n)<<endl;

	return 0;
}

