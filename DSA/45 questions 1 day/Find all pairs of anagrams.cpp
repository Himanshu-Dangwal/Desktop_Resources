//Find all pairs of anagrams::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

vector<vector<string>> getAnagrams(vector<string> &a){
	unordered_map<string,vector<string>> m;
	for(int i=0;i<a.size();i++){
		string str = a[i];
		sort(str.begin(),str.end());
		m[str].push_back(a[i]);
	}
	
	vector<vector<string>> ans(m.size());
	int idx = 0;
	for(auto x : m){
		auto v = x.second;
		
		for(int i=0;i<v.size();i++){
			ans[idx].push_back(v[i]);
		}
		
		idx++;
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	
	vector<string> a(n);
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		a[i] = s;
	}
	vector<vector<string>> ans;
	ans = getAnagrams(a);
	
	cout<<endl;
	
	for(int i=0;i<ans.size();i++){
		if(ans[i].size() > 1){
			for(int j=0;j<ans[i].size();j++){
				cout<<ans[i][j]<<endl;
			}	
		}
	}
	
	return 0;
}

