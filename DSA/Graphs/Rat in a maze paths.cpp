//Rat in a maze problem::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

vector<string> getPaths(int si,int sj,int ei,int ej,vector<vector<int>> &arr,bool** visited){
	
	if(si<0 || si>=arr.size() || sj<0 || sj >= arr[0].size() || arr[si][sj] == 1 || visited[si][sj])
	{
		vector<string> ans;
		return ans;	
	}	
	
	if(si == ei && sj == ej){
		vector<string> ans;
		string s = "";
		ans.push_back(s);
		return ans;
	}
	
	visited[si][sj] = true;
	
	vector<string> pathR = getPaths(si,sj+1,ei,ej,arr,visited);
	vector<string> pathD = getPaths(si+1,sj,ei,ej,arr,visited);
	vector<string> pathL = getPaths(si,sj-1,ei,ej,arr,visited);
	vector<string> pathT = getPaths(si-1,sj,ei,ej,arr,visited);
	
	vector<string> ans;
	
	for(auto path : pathR){
		ans.push_back("R" + path);
	}
	
	for(auto path : pathD){
		ans.push_back("D" + path);
	}
	
	for(auto path : pathL){
		ans.push_back("L" + path);
	}
	
	for(auto path : pathT){
		ans.push_back("T" + path);
	}
	visited[si][sj] = false;
	return ans;
}


int main(){
	int n,m;
	cin>>n>>m;
	
	vector<vector<int>> arr(n);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int x;
			cin>>x;
			arr[i].push_back(x);
		}
	}
	
	bool** visited = new bool*[n];
	for(int i=0;i<n;i++){
		visited[i] = new bool[n];
		for(int j=0;j<m;j++){
			visited[i][j] = false;
		}
	}
	
	vector<string> ans = getPaths(0,0,n-1,m-1,arr,visited);
	
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}

	return 0;
}

