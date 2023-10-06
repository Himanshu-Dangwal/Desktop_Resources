#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    
    int arr1[n];
    
    int max_val = INT_MIN;
    for(int i=0;i<n;i++){
        cin>>arr1[i];
        
        max_val = max(max_val,arr1[i]);
    }
    
    
    unordered_map<int,vector<int>> m;
    
    vector<int> indices(max_val+1,0);
    
    int arr2[n];
    for(int i=0;i<n;i++){
        cin>>arr2[i];
        m[arr2[i]].push_back(i);
        // cout<<m[arr2[i]]<<" ";
    }
    // cout<<endl;
    
    // cout<<m[1]<<endl;
    // cout<<m[1].size();
    // cout<<m[2].size()<<endl;
    
    for(int i=0;i<n;i++){
        int a = arr1[i];
        
        // cout<<m[1]<<" ";
        
        vector<int> x = m[a];
        
        // cout<<x.size()<<endl;
        
        int index = indices[a];
        cout<<x[index]<<" ";
        
        indices[a]++;
        
        // cout<<a<<" ";
        // cout<<m[a]<<" ";
    }
}
