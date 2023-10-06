#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	string s;
	cin>>s;
	
	unordered_map<char,int> m;
	
	for(int i=0;i<s.length();i++){
		m[s[i]]++;
	}
	
	cout<<m.size()<<endl;
	
	for(auto it : m){
		cout<<it.first<<" ";
	}
	
	return 0;
}

