//Arrange Ways to make Bulding and Spaces:::

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	if(n==0){
		cout<<0<<endl;
		exit(0);
	}
	int ob = 1;
	int os = 1;
	
	int nb,ns;
	
	for(int i=2;i<=n;i++){
		nb = os;
		ns = ob + os;
		
		ob = nb;
		os = ns;
	}
	int total = os + ob;
	total = total * total;
	cout<<endl;
	cout<<total<<endl;
}
