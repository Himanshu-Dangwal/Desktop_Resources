#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;


void toh(int n,int src,int dest,int aux){
	
	if(n==0){
		return ;
	}
	
	toh(n-1,src,aux,dest);
	cout<<src<<" - > "<<dest<<endl;
	toh(n-1,aux,dest,src);
	
}

int main(){
	
	int n;
	cin>>n;
	
	toh(n,1,2,3);

	return 0;
}

