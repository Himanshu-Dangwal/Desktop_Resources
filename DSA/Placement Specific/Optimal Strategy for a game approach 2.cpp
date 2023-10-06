#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin>>n;
    
    vector<int> arr(n);
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
    }
    
    int dp[n][n];
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;i++,j++){
            if(g == 0){
                dp[i][j] = arr[i];
            }else{
                int pAns1 = arr[i] - dp[i+1][j];
                int pAns2 = arr[j] - dp[i][j-1];
                
                dp[i][j] = max(pAns1,pAns2);
            }
        }
    }
    
    ll value = (sum + dp[0][n-1])/2;
    cout<<value;
    return 0;
}
