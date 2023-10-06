//1, 3, 1, 5,              11  5   8    16
//2, 2, 4, 1},			  2  7   11   12
//5, 0, 2, 3},			  5  5   9    15
//0, 6, 1, 2}}			  01  12   14

#include<bits/stdc++.h>
using namespace std;

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
	//Coulm 0
	for(int i=0;i<n;i++){
		dp[i][0] = arr[i][0];
	}
	
	for(int col = 1;col < m;col++){
		for(int row = 0;row < n;row++){
			if(row == 0){
				dp[row][col] = max(dp[row][col-1],dp[row+1][col-1]) + arr[row][col];
			}
			else if(row == n-1){
				dp[row][col] = max(dp[row][col-1],dp[row-1][col-1]) + arr[row][col];
			}else{
				dp[row][col] = max(dp[row][col-1],max(dp[row+1][col-1],dp[row-1][col-1]))+ arr[row][col];
			}
		}
	}
	
	int max_val = INT_MIN;
	for(int i=0;i<n;i++){
		if(dp[i][m-1] > max_val){
			max_val = dp[i][m-1];
		}
	}
	
	cout<<max_val<<endl;
}

