#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

vector<string> getPaths(int si,int sj,int ei,int ej){
	
	if(si == ei  &&  sj == ej){
		vector<string> ans;
		string s = "";
		ans.push_back(s);
		return ans;
	}
	
	
	vector<string> paths1;
	
	if(sj < ej)
		paths1 = getPaths(si,sj+1,ei,ej);
	
	vector<string> paths2;
	if(si < ei)
		paths2 = getPaths(si+1,sj,ei,ej);
	
	vector<string> ans;
	for(auto path : paths1){
		ans.push_back('h' + path);
	}
	
	for(auto path : paths2){
		ans.push_back('v' + path);
	}
	
	return ans;
	
}


int main(){
	
	int n;
	cin>>n;
	
	vector<string> ans = getPaths(0,0,n-1,n-1);
	
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}

	return 0;
}

