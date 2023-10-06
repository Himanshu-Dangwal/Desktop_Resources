#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;
    cin>>n;
    
    int arr[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    unordered_set<int> s;
    
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int curr_sum = arr[i] + arr[j];
            if(s.find(curr_sum) != s.end()){
                cout<<"true";
                return 0;
            }else{
                s.insert(curr_sum);
            }
        }
    }
    cout<<"false";
    return 0;
}
