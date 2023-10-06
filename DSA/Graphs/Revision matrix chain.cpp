#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	n--;
	
	int dp[n][n];
	for(int g=0;g<n;g++){
		for(int i=0,j=g;j<n;i++,j++){
			if(g == 0){
				dp[i][j] = 0;
			}else if(g == 1){
				dp[i][j] = arr[i]*arr[j]*arr[j+1];
			}else{
				int curr_sum = INT_MAX;
				for(int k=i;k<j;k++){
					int ls = dp[i][k];
					int rs = dp[k+1][j];
					
					int ms = arr[i] * arr[k+1] * arr[j+1];
					
					int total_sum = ls + rs + ms;
					
					if(total_sum < curr_sum){
						curr_sum = total_sum;
					}
				}
				
				dp[i][j] = curr_sum;
				
			}
		}
	}
	
	cout<<dp[0][n-1]<<endl;
}
