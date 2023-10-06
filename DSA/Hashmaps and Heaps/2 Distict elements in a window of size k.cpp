//Distinct Elements in a window of size k::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	unordered_map<int,int> m;
	int k;
	cin>>k;
	for(int i=0;i<k-1;i++){
		m[arr[i]]++;
	}
	
	vector<int> ans;
	
	int j=0;
	
	for(int i=k-1;i<n;i++){
		m[arr[i]]++;
		ans.push_back(m.size());
		m[arr[j]]--;
		if(m[arr[j]] == 0)
			m.erase(arr[j]);
		j++;	
	}
	cout<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	
	return 0;
}


//13
//
//1 2 3 3 2 4 5 6 5 7 7 7 8 
//
//3
//
//3 2 2 3 3 3 2 3 2 1 2





