#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    
    unordered_set<char> st;
    for(int i=0;i<s.length();i++){
        st.insert(s[i]);
    }
    
    int ans = s.length();
    
    int i=-1;
    int j=-1;
    
    unordered_map<char,int> m;
    
    while(true){
        bool flag1 = false;
        bool flag2 = false;
        
        //acquire
        
        int n = s.length() - 1;
        while(i < n && m.size() < st.size()){
            
            i++;
            m[s[i]]++;
            flag1 = true;
             
        }
        
        //calculate and release
        
        while(j < i  &&  m.size() == st.size()){
            
            int pAns = i - j;
            if(pAns < ans){
                ans = pAns;
            }
            
            j++;
            m[s[j]]--;
            
            if(m[s[j]] == 0){
                m.erase(s[j]);
            }
            
            flag2 = true;
        }
        
        if(flag1 ==  false && flag2 == false){
            break;
        }
        
    }
    
    cout<<ans<<endl;
    
}



