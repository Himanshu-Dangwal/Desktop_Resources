//Arrange Buildings and Spaces::
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int ob = 1;
	int os = 1;
	
	for(int i=2;i<=n;i++){
		int ns = ob+os;
		int nb = os;
		
		os = ns;
		ob = nb;
	}
	cout<<ob+os<<endl;
	return 0;
}

