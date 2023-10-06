//Champagne Tower::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

double find(int poured,int row,int col){
	double dp[row+1][col+1];
	for(int i=0;i<=row;i++){
		for(int j=0;j<=i;j++){
			dp[i][j] = 0.00;
		}
	}	
	dp[0][0] = poured;

	for(int i=0;i<row;i++){
		for(int j=0;j<=i;j++){
			double left = 0.00;
			if(dp[i][j] > 1.00){
				left = dp[i][j] - 1.00;
				dp[i][j] = 1.00;	
			}
			dp[i+1][j] += ((double)left/2.00);
			dp[i+1][j+1] += ((double)left/2.00);
			left = 0.00;
		}
	}
	
	if(dp[row][col] > 1.00){
		return 1.00;
	}
	return dp[row][col];
}

int main(){
	int poured,row,col;
	cin>>poured>>row>>col;
	
	cout<<find(poured,row,col);

	return 0;
}

