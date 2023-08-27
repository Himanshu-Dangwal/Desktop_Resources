#include<bits/stdc++.h>
using namespace std;
int main(){
map<int,string> m;
string s;
    cin>>s;  
    int k=0;
    int u=0;
    for(int i=0;i<s.length();i++){
		if(s[i]==';'){
			m[u]=s.substr(k,i-k);
            k=i+1;
            u++;
        }if(i==s.length()-1){
        	m[u]=s.substr(k,i-k+1);
        	k=i+1;
        	u++;
		}
    }
    for(int i=0;i<u;i++){
    	cout<<m[i]<<endl;
	}
}
