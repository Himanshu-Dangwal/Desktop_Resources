//Celebrity Problem::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	int n;
	cin>>n;
	int M[n][n];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>M[i][j];
		}	
	}
	
	int i=0;
	int j=n-1;
	
	while(i<j){
		if(M[j][i] == 1){
			j--;
		}else{
			i++;
		}
	}
	
	int candidate = i;
	bool flag = true;
//	cout<<candidate<<endl;
	for(int i=0;i<n;i++){
		if(i!=candidate){
//			cout<<candidate<<" "<<i<<endl;
			if(M[candidate][i] == 1 || M[i][candidate] == 0){
				cout<<"No celebrity"<<endl;
				flag = false;
				break;
			}
		}
	}
	
	if(flag){
		cout<<candidate+1<<endl;
	}
	
	
	return 0;
}

