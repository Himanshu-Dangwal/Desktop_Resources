#include<bits/stdc++.h>
using namespace std;


int main(){
	int N,H,x;
	cin>>N>>H>>x;
	int a[N];
	for(int i=0;i<N;i++){
		cin>>a[i];
	}	
	sort(a,a+N);
	if(x+a[N-1] >=H){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
}
