#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;


    int minScoreTriangulation(vector<int>& arr) {
        int n = arr.size();
        if(n == 3){
            return arr[0]*arr[1]*arr[2];
        }
        
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int g=2;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g == 2){
                    dp[i][j] = arr[i]*arr[i+1]*arr[j];
                }else{
                    int min_val = INT_MAX;
                    for(int k=i+1;k<j;k++){
                        int mc = arr[i]*arr[k]*arr[j];
                        int lc = dp[i][k];
                        int rc = dp[k][j];
                        
                        int tc = mc + lc + rc;
                        if(tc < min_val) min_val = tc;
                    }
                    dp[i][j] = min_val;
                }
            }
        }
       /* 
        for(int i=0;i<n;i++){
        	for(int j=0;j<n;j++){
        		cout<<dp[i][j]<<"   ";
			}
			cout<<endl;
		}
        */
        return dp[0][n-1];
        
    }

int main(){
	int n;
	cin>>n;
	
	vector<int> arr;
	for(int i=0;i<n;i++){
		int x; cin>>x;
		arr.push_back(x);
	}
	
	cout<<minScoreTriangulation(arr);

	return 0;
}

