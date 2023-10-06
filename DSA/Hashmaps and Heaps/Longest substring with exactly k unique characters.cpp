#include<bits/stdc++.h>
using namespace std;

int main(){
    
    string s;
    cin>>s;
    
    int k;
    cin>>k;
    
    unordered_map<char,int> m;
    
    int i=-1;
    int j=-1;
    
    int n = s.length();
    // n--;
    int count = 0;
    
    int ans = -1;
    
    
    while(true){
        
        bool flag1 = false;
        bool flag2 = false;
        
        while(i < n && count <= k){
            //acquire;
            
            if(count == k){
                int pans = i - j;
            
                if(pans > ans){
                    ans = pans;
                }
            }
            
            flag1 = true;
            i++;
            m[s[i]]++;
        
            count = m.size();
            
        }
        
        while(j < i && count > k){
            
            flag2 = true;
            
            j++;
            m[s[j]]--;
            
            if(m[s[j]] == 0){
                m.erase(s[j]);
                count--;
            }
            
        }
        
        if(!flag1 && !flag2){
            break;
        }
        
    }
    
    cout<<ans<<endl;
}
