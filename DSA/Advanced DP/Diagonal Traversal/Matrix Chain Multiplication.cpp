//Matrix Chain Multiplication::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int minOperations(int x,int* arr){
	
	int n = x-1;
	
	int dp[n][n];
	
	
	
	for(int g=0;g<n;g++){
		
		for(int i=0,j=g; j < n;i++,j++){
			
			if(g == 0){
				dp[i][j] = 0;
			}else if(g == 1){
				dp[i][j] = arr[i] * arr[j] * arr[j+1]; 
			}else{
				int min_operations = INT_MAX;
				for(int k = i;k < j;k++){
					
					int ls = dp[i][k];
					int rs = dp[k+1][j];
					
					int ms = arr[i] * arr[k+1] * arr[j+1];
					
					int to = ls + rs + ts;
					
					if(to < min_operations)
						min_operations = to;
					
				}
				dp[i][j] = min_operations;
				
			}
			
		}
		
	}
	
	
	return dp[0][n-1];
}


int main(){
	int n;
	cin>>n;
	
	int* arr = new int[n];
	for(int i=0;i<n;cin>>arr[i++]);
	
	cout<<minOperations(n,arr);
	
	return 0;
}

