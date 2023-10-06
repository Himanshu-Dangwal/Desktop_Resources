#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int sum = 0;
    int count = 0;
    
    unordered_map<int,int> m;
    m[0] = 1;
    
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
            count += m[sum];
            m[sum]++;
        }else{
            m[sum] = 1;
        }
    }
    cout<<count;
}
