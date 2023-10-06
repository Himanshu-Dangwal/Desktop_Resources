//Merge k sorted arrays::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
#define pii pair<int,int>
typedef long long ll;

int main(){
	int k;
	cin>>k;
	
	vector<vector<int>> a(k);
	
	for(int i=0;i<k;i++){
		int size;
		cin>>size;
		a[i] = vector<int>(size);
		for(int j=0;j<size;j++){
			cin>>a[i][j];
		}
	}
	
	vector<int> indices(k,0);
	
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	for(int i=0;i<k;i++){
		pq.push(make_pair(a[i][0],i));
	}
	
	vector<int> ans;
	
	while(!pq.empty()){
		pii x= pq.top();
		pq.pop();
		ans.push_back(x.first);
		
		if(indices[x.second]+1 < a[x.second].size()){
			pq.push(make_pair(a[x.second][indices[x.second]+1],x.second));
		}
		indices[x.second]+=1;
	}
	cout<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

