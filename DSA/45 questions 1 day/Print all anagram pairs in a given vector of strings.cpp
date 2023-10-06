//Given a vector of string.WAP to print all anagram pairs::::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	int n;
	cin>>n;
	vector<string> words;
	
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		words.push_back(s);
	}
	
	map<string,vector<string>> m;
	
	for(int i=0;i<n;i++){
		string s = words[i];
		string t = s;
		
		sort(s.begin(),s.end());
		
		m[s].push_back(t);
	}
	
	vector<pair<string,string>> pairOfString;
	
	for(auto it : m){
		int n = it.second.size();
		if(n==1){
			continue;
		}
		if(n==2){
			pairOfString.push_back(make_pair(it.second[0],it.second[1]));
			continue;
		}
		for(int i=0;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				pairOfString.push_back(make_pair(it.second[i],it.second[j]));
			}
		}
	}
	
	
	for(int i=0;i<pairOfString.size();i++){
		cout<<pairOfString[i].first<<" "<<pairOfString[i].second<<endl;
	}
	
	
	return 0;
}

