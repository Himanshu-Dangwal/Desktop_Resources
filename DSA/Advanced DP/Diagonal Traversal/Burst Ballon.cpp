#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;


    int maxCoins(vector<int>& arr) {
        
        int n = arr.size();
        if(n == 1){
        	return arr[0];
		}
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g == 0){
                    if(i==0){
                        dp[i][j] = arr[i] * arr[i+1];
                    }else if(j==n-1){
                        dp[i][j] = arr[i] * arr[i-1];
                    }else{
                        dp[i][j] = arr[i-1] * arr[i] * arr[i+1];
                     }
                }else{
                    
                    int max_val = INT_MIN;
                    for(int k=i;k<=j;k++){
                        int lc = k == i ? 0 : dp[i][k-1];
                        int rc = k == j ? 0 : dp[k+1][j];
                        
                        int mc = arr[k];;
                        if(i > 0){
                            mc = mc * arr[i-1];
                        }
                        if(j < n-1){
                            mc = mc * arr[j+1];
                        }
                        int tc = lc + rc + mc;
                        if(tc > max_val) max_val = tc;
                    }
                    dp[i][j] = max_val;
                }
            }
        }
        
        
        for(int i=0;i<n;i++){
        	for(int j=0;j<n;j++){
        		cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
        
        
        return dp[0][n-1];
    }


int main(){
	
	vector<int> arr;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr.push_back(x);
	}
	
	cout<<maxCoins(arr);

	return 0;
}

