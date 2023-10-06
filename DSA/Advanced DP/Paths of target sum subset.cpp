//Print all subsets with a given target sum::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

struct triplet{
	int i,j;
	string psf; //path so far::
	
	triplet(int a,int b,string s){
		this->i = a;
		this->j = b;
		this->psf = s;
	}
};

int main(){
	int n,target;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	
	cin>>target;
	
	bool dp[n+1][target+1];
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=target;j++){
			if(i==0 && j==0){
				dp[i][j] = true;
			}else if(i==0){
				dp[i][j] = false;
			}else if(j==0){
				dp[i][j] = true;
			}else{
				dp[i][j] = dp[i-1][j];
				if(j >= arr[i-1]){
					dp[i][j] = dp[i][j] || dp[i][j-arr[i-1]];
				}
			}
		}
	}
	
	queue<triplet> q;
	triplet t(n,target,"");
	q.push(t);
	
	while(!q.empty()){
		triplet rem = q.front();
		q.pop();
		
		if(rem.i == 0 || rem.j == 0){
			cout<<rem.psf<<endl;
			continue;
		}
		
		bool exclude = dp[rem.i - 1][rem.j]; 
		if(exclude){
			triplet temp(rem.i-1,rem.j,rem.psf);
			q.push(temp);
		}
		
		if(rem.j >= arr[rem.i - 1]){
			bool include = dp[rem.i - 1][rem.j - arr[rem.i-1]];
			if(include){
				triplet temp(rem.i-1,rem.j - arr[rem.i - 1],to_string(arr[rem.i-1]) + " " + rem.psf);
				q.push(temp);
			}
		}
	}
	
	return 0;
}

