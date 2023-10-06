#include<bits/stdc++.h>
using namespace std;

class Job{
  public:
    int start,finish,profit;
};

bool compare(Job a,Job b){
    return a.finish<b.finish;
}

int mp(Job arr[],int n){
    sort(arr,arr+n,compare);
    int dp[n];
    dp[0] = arr[0].profit;
    
    for(int i=1;i<n;i++){
        int lNonConflicting = -1;
        int exclude = dp[i-1];
        for(int j=i-1;j>=0;j--){
            if(arr[j].finish <= arr[i].start){
                lNonConflicting = j;
                break;
            }
        }
        int include = INT_MIN;
        if(lNonConflicting != -1){
            include = dp[lNonConflicting] + arr[i].profit;
        }
        dp[i] = max(include,exclude);
    }
    
    return dp[n-1];
}

int main(){
    int n;
    cin>>n;
    Job arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].start>>arr[i].finish>>arr[i].profit;
    }
    cout<<mp(arr,n)<<endl; //Maximum Profit::   
    return 0;
}