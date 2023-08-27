#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	string s;
	vector<int> v;
	cin>>t;
	
	while(t--){
		cin>>s;
		int n = s.length();
		int i=0;
		int count = 0;
		while(i<n){
			while(s[i]!='1' && i<n){
				i++;
			}
			if(i==n){
				break;
			}
			if(s[i]=='1'){
				count+=1;
			}
			if(i<n){
				int j = i+1;
				while(s[j]!='0' && j<n){
					j++;
				}
				i=j+1;
			}
		}
		v.push_back(count);
	}
	for (auto k = v.begin(); k != v.end(); ++k) 
        cout << *k <<endl; 
}
