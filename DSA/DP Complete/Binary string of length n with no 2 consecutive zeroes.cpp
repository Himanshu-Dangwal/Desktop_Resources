#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	
	int n;
	cin>>n;
	int old_zeroes = 1;
	int old_ones = 1;
	
	for(int i=2;i<=n;i++){
		int new_ones =  old_zeroes + old_ones ;
		int new_zeroes = old_ones ;
		
		old_zeroes = new_zeroes;
		old_ones = new_ones;
	}
	
	cout<<old_zeroes + old_ones <<endl;

	return 0;
}

