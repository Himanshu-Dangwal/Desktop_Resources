//Paint Houses With Many Colours::

#include<bits/stdc++.h>
using namespace std;
//Time Complexity = O(n^3)::
//Can be Optimised to O(n^2)::
int main(){
	int n; //Number Of Houses::
	cin>>n;
	int c; //Number of Colours::
	cin>>c;
	int arr[n][c];
	for(int i=0;i<n;i++){
		for(int j=0;j<c;j++){
			cin>>arr[i][j];
		}
	}
	int dp[n][c];
	//Keeping the first Row the same::
	for(int i=0;i<c;i++){
		dp[0][i] = arr[0][i];
	}
	
	for(int i=1;i<n;i++){
		for(int j=0;j<c;j++){
			int min_val = INT_MAX;
			int row = i-1;
			//Loop To find the min val till the row we are filling currently::
			for(int k=0;k<c;k++){
				if(k==j)
					continue;
				else{
					if(dp[row][k] < min_val)
						min_val = dp[row][k];
				}	
			}
			dp[i][j] = arr[i][j] + min_val;
		}
	}
	//Now fimding the minimum value in the last row::
	int min_val = INT_MAX;
	for(int i=0;i<c;i++){
		if(dp[n-1][i] < min_val){
			min_val = dp[n-1][i];
		}
	}
	cout<<endl;
	cout<<min_val<<endl;;
}

