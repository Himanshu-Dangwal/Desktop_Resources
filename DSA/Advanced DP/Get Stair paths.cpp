//Get Stairs Path
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

vector<string> getPaths(int n){
	
	if(n==0){
		vector<string> ans ;
		string s = "";
		ans.push_back(s);
		return ans;
	}else if(n<0){
		vector<string> ans;
		return ans;
	}
	
	vector<string> paths1 = getPaths(n-1);
	vector<string> paths2 = getPaths(n-2);
	vector<string> paths3 = getPaths(n-3);
	
	vector<string> ans;
	
	for(string path : paths1){
		ans.push_back('1' + path);
	}

	for(string path : paths2){
		ans.push_back('2' + path);
	}
	
	for(string path : paths3){
		ans.push_back('3' + path);
	}
	
	return ans;
}


int main(){
	int n;
	cin>>n;
	
	vector<string> ans = getPaths(n);
	
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}

	return 0;
}

