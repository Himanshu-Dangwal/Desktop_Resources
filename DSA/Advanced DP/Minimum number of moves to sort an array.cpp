#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int getMinSwaps(int arr[],int n){
	
	vector<bool> visited(n,false);
	
	vector<pair<int,int>> a;
	for(int i=0;i<n;i++){
		a.push_back(make_pair(arr[i],i));
	}
	
	sort(a.begin(),a.end());
	
	int ans = 0;
	
	for(int i=0;i<n;i++){
		
		if(visited[i] == true  ||  a[i].second == i){
			continue;
		}
		
		int clen = 0;
		int j = i;
		while(visited[j] != true){
			clen++;
			visited[j] = true;
			j = a[j].second;
		}
		ans += (clen - 1);
	}
	
	return ans;
}


int main(){
	
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;cin>>arr[i++]);
	
	cout<<getMinSwaps(arr,n);
	
	return 0;
}

