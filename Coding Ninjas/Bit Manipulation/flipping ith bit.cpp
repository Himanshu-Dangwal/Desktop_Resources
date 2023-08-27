//FLip ith bit
#include<bits/stdc++.h>
using namespace std;

int flip(int n,int i){
	n = n^(1<<i);
	return n;
}

int main(){
	int n;
	int>>n;
	int i;
	cin>>i;
	cout<<flip(n,i);
}
