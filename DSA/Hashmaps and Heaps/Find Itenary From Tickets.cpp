#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    unordered_map<string,bool> m;
    
    unordered_map<string,string> map2;
    
    for(int i=0;i<n;i++){
        string src,dest;
        cin>>src>>dest;
        
        map2[src] = dest;
        
        if(m.find(src) == m.end()){
            m[src] = true;
        }else{
            m[src] = false;
        }
        m[dest] = false;
    }
    
    string osrc;
    for(auto it : m){
        string dest = it.first;
        if(m[dest] == true){
            osrc = dest;
            break;
        }
    }
    string curr_src = osrc;
    
    cout<<curr_src;
    
    while(map2.find(curr_src) != map2.end()){
        
        cout<<" -> "<<map2[curr_src];
        curr_src = map2[curr_src];
    }
    
    cout<<".";
    
    
}
