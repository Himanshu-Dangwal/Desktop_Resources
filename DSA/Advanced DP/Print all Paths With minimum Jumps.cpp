//Print all Paths With Minimum Jumps::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

struct Pair{
	int idx,val;
	string psf;
	
	Pair(int a,int b,string s){
		this->idx = a;
		this->val = b;
		this->psf = s;
	}
};

int main(){
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int dp[n];
	dp[n-1] = 0;
	
	for(int i=n-2;i>=0;i--){
		if(arr[i] == 0){
			dp[i] = INT_MAX;
			continue;
		}else{
			int count = arr[i];
			int min_val = INT_MAX;
			for(int j= 1;j<=count;j++){
				if(i+j <n && dp[i+j] != INT_MAX  && dp[i+j] < min_val){
					min_val = dp[i+j];
				}
			}
			dp[i] = min_val + 1;
		}
	}
	cout<<dp[0]<<endl;
	
	queue<Pair> q;
	string s = "";
	Pair p(0,dp[0],s);
	q.push(p);
	
	while(!q.empty()){
		Pair rem = q.front();
		q.pop();
		
		if(rem.idx == n-1){
			cout<<rem.psf<<endl;
			continue;
		}
		
		for(int i=1;i<=arr[rem.idx];i++){
			if(dp[rem.idx + i] == rem.val - 1){
				Pair t(rem.idx + i,rem.val-1,rem.psf + to_string(i));
				q.push(t);
			}
		}
	}	
	
	return 0;
}



















