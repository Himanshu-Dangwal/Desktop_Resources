//Nth root of an integer ::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

double multiply(double val,int n){
	double ans = 1.0; 
	for(int i=1;i<=n;i++){
		ans =  ans * val; 
	}
	return ans;
}

void getNthRoot(int n,int m){
	double l = 1;
	double h = m;
	
	double esp = 1e-6;
	double ans = 0.0;
	bool flag = false;
	while((h - l) > esp){
		double mid = (h + l)/2.0;
		double check = multiply(mid,n);
		
		if(check < m){
			l = mid;
		}else{
			h = mid;
		}
	}
	
	
	cout<<"Checking"<<endl;
	cout<<pow(m,(double)(1.0/(double)n))<<endl;
	
	cout<<"Root lies in range "<<l<<" "<<h<<endl;
	return;
}


int main(){
	int n,m;
	cin>>n>>m;
	
	getNthRoot(n,m);

	return 0;
}

