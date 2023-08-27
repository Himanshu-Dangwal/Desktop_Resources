//Mindbending Product

#include<iostream>
using namespace std;

typedef long long ll;

void product(int *a,int n,int *p){
	int lpa=1;
	int rpa=1;
	for(int i=0;i<n;i++){
		if(i==0)
			p[i]=1;
		else{
			lpa=lpa*a[i-1];
			p[i]=lpa;
		}	
	}
	for(int i=n-1;i>=0;i--){
		if(i==n-1){
			continue;
		}
		else{
			rpa=rpa*a[i+1];
			p[i]=p[i]*rpa;
		}
	}
}

int main(){
	int n;
	cin>>n;
	int a[n];
	int p[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	product(a,n,p);
	for(int i=0;i<n;i++){
		cout<<p[i]<<endl;
	}
	return 0;
}
