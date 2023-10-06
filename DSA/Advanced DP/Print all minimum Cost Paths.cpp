//Print all Minimum Cost Paths::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

struct triplet{
	int x,y;
	string psf;
	
	triplet(int a,int b,string s){
		this->x = a;
		this->y = b;
		this->psf = s;
	}
};

int main(){
	int n,m;
	cin>>n>>m;
	
	int arr[n][m];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	
	int dp[n][m];
	
	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=0;j--){
			if(i==n-1 && j==m-1){
				dp[i][j] = arr[i][j];
			}else if(j == m-1){
				dp[i][j] = arr[i][j] + dp[i+1][j];
			}else if(i == n-1){
				dp[i][j] = arr[i][j] + dp[i][j+1];
			}else{
				dp[i][j] = arr[i][j] + min(dp[i+1][j],dp[i][j+1]);
			}
		}
	}

	queue<triplet> q;
	string s = "";
	triplet t(0,0,s);
	q.push(t);
	
	while(!q.empty()){
		triplet rem = q.front();
		q.pop();
			
		if(rem.x == n-1 && rem.y == m-1){
			cout<<rem.psf<<endl;
		}else if(rem.x == n-1){
			triplet t(rem.x,rem.y+1,rem.psf + 'H');
			q.push(t);
		}else if(rem.y == m-1){
			triplet t(rem.x + 1,rem.y,rem.psf + 'V');
			q.push(t);
		}else{
			if(dp[rem.x][rem.y + 1] < dp[rem.x + 1][rem.y]){
				triplet t(rem.x,rem.y+1,rem.psf + 'H');
				q.push(t);
			}else if(dp[rem.x][rem.y + 1] > dp[rem.x + 1][rem.y]){
				triplet t(rem.x + 1,rem.y,rem.psf + 'V');
				q.push(t);
			}else{
				triplet t(rem.x,rem.y+1,rem.psf + 'H');
				q.push(t);
				triplet m(rem.x + 1,rem.y,rem.psf + 'V');
				q.push(m);
			}
		}
	}
	return 0;
}









