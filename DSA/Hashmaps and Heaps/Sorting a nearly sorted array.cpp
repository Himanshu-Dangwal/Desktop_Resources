//Sorting a nearly sorted array::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

//9
//2 3 1 4 6 7 5 8 9
//2

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	
	int arr[n];
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int k;
	cin>>k;
	
	priority_queue<int,vector<int>,greater<int>> pq;
	
	for(int i=0;i<=k;i++){
		pq.push(arr[i]);
	}
	
	vector<int> ans;
	
	for(int i=k+1;i<n;i++){
		int x = pq.top();
		pq.pop();
		ans.push_back(x);
		pq.push(arr[i]);
	}
	
	while(!pq.empty()){
		int x = pq.top();
		ans.push_back(x);
		pq.pop();
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	
	return 0;
}

