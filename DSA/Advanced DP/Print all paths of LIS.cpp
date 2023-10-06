//LIS
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

struct triplet{
	int l;
	int i;
	int v;
	string psf;
	
	triplet(int l,int i,int v,string s){
		this->l = l;
		this->i = i;
		this->v = v;
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
	
	dp[0] = 1;
	int max_val = INT_MIN;
	for(int i=1;i<n;i++){
		dp[i] = 1;
		for(int j=0;j<i;j++){
			if(arr[j] <= arr[i]){
				dp[i] = max(dp[i],dp[j] + 1);
			}
		}
		max_val = max(max_val,dp[i]);
	}
	
	
	queue<triplet> q;
	
	for(int i=0;i<n;i++){
		if(dp[i] == max_val){
			string s = "";
			triplet p(dp[i],i,arr[i],to_string(arr[i])+ s);
			q.push(p);
		}
	}
	
	while(!q.empty()){
		triplet rem = q.front();
		q.pop();
		
		if(rem.l == 1){
			cout<<rem.psf<<endl;
			continue;
		}
		
		for(int j=0;j<rem.i;j++){
			if(dp[j] == rem.l -1 && arr[j] < rem.v){
				triplet temp(dp[j],j,arr[j],to_string(arr[j]) + " -> " + rem.psf);
				q.push(temp);
			}
		}
	}
	
	return 0;
}

