#include<bits/stdc++.h>
using namespace std;

int main(){
    
    string s1,s2;
    cin>>s1>>s2;
    
    int k;
    cin>>k;
    
    if(s1.length() != s2.length()){
        cout<<"false";
        return 0;
    }
    
    unordered_map<char,int> map1;
    unordered_map<char,int> map2;
    
    for(int i=0;i<s1.length();i++){
        map1[s1[i]]++;
    }
    
    for(int i=0;i<s2.length();i++){
        map2[s2[i]]++;
    }
    
    int counter = 0;
    
    // int len = max(map1.size(),map2.size());
    
    vector<char> removed;
    
    for(auto it : map1){
        char ch = it.first;
        
        if(map2.find(ch) == map2.end()){
            // cout<<"Here for "<<ch<<endl;
            counter = counter + map1[ch];
            // map1.erase(ch);
            removed.push_back(ch);
            continue;
        }else{
            counter = counter + abs(map1[ch] - map2[ch]);
            // cout<<counter<<" for character "<<ch<<endl;
            // map1.erase(ch);
            // map2.erase(ch);
            removed.push_back(ch);
        }
        // cout<<counter<<endl;
        // counter = counter + abs(map1[ch] - map2[ch]);
        // map1.erase(ch);
        // map2.erase(ch);
        // cout<<map1.size()<<" "<<map2.size()<<endl;
    }
    
    for(int i=0;i<removed.size();i++){
        char ch = removed[i];
        map1.erase(ch);
        
        if(map2.find(ch) != map2.end()){
            map2.erase(ch);
        }
        
    }
    
    // cout<<map2.size()<<endl;
    
    for(auto it: map2){
        
        char ch = it.first;
        
    
        counter = counter + map2[ch];
        // map2.erase(ch);
    
    }
    // cout<<counter<<endl;
    int check = counter/2;
    
    if(check <= k){
        cout<<"true";
    }else{
        cout<<"false";
    }
    
    
}
