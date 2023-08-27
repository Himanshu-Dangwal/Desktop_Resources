//Paint Houses Code Optimisation using least and sleast method::
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int c;
	cin>>c;
	int arr[n][c];
	for(int i=0;i<n;i++){
		for(int j=0;j<c;j++){
			cin>>arr[i][j];
		}
	}
	int least = INT_MAX;
	int sleast = INT_MAX;
	int dp[n][c];
	//WOrking for the first Row::
	for(int col=0;col<c;col++){
		dp[0][col] = arr[0][col];
		if(dp[0][col] <= least){
			sleast = least;
			least = dp[0][col];
		}else if(dp[0][col] <= sleast){
			sleast = dp[0][col];
		}
	}
	//Now for all the remaining Houses::
	for(int i=1;i<n;i++){
		int nleast = INT_MAX;
		int nsleast = INT_MAX;
		for(int j=0;j<c;j++){
			if(dp[i-1][j] == least){
				//Choose sleast::
				dp[i][j] = sleast + arr[i][j];
			}else{
				//Choose least::
				dp[i][j] = least + arr[i][j];
			}
			
			if(dp[i][j] <= nleast){
				nsleast = nleast;
				nleast = dp[i][j];
			}else if(dp[i][j] <= nsleast){
				nsleast = dp[i][j];
			}
		}
		least = nleast;
		sleast = nsleast;
	}
	//Now traversing the last row to find the minimum value::
	int min_val = INT_MAX;
	for(int i=0;i<c;i++){
		if(dp[n-1][i] < min_val){
			min_val = dp[n-1][i];
		}
	}
	cout<<endl;
	cout<<min_val<<endl;
}

