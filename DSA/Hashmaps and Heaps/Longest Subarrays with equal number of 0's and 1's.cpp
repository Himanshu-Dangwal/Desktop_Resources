#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int sum = 0;
    int ans = 0;
    
    unordered_map<int,int> m;
    m[0] = -1;
    
    int arr[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            sum += -1;
        }else{
            sum += 1;
        }
        
        if(m.find(sum) != m.end()){
            int pl = i - m[sum];
            if(pl > ans){
                ans = pl;
            }
            // m[sum]++;
        }else{
            m[sum] = i;
        }
    }
    cout<<ans;
}
