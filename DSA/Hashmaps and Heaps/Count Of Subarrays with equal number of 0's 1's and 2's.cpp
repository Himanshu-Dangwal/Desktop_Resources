#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    unordered_map<string,int> m;
    string s = "0#0";
    m[s] = 1;
    
    int cz = 0;
    int co = 0;
    int ct = 0;
    
    int ans = 0;
    
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            cz += 1;
        }else if(arr[i] == 1){
            co += 1;
        }else{
            ct += 1;
        }
        
        int start = co - cz;
        int end = ct - co;
        
        string s = to_string(start) + "#" + to_string(end);
        if(m.find(s) != m.end()){
            ans += m[s];
            m[s]++;
        }else{
            m[s] = 1;
        }
    }
    
    cout<<ans;
}
