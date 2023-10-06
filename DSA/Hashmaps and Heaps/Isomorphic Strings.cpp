#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1,s2;
    
    cin>>s1>>s2;
    
    unordered_map<char,char> map1;
    unordered_map<char,bool> map2;
    
    for(int i=0;i<s1.length();i++){
        if(map1.find(s1[i]) == map1.end()){
            if(map2.find(s2[i]) != map2.end()){
                cout<<"false";
                return 0;
            }else{
                map1[s1[i]] = s2[i];
                map2[s2[i]] = true;
            }
        }else{
            if(map1[s1[i]] != s2[i]){
                cout<<"false";
                return 0;
            }
        }
    }
    
    cout<<"true";
    return 0;
}
