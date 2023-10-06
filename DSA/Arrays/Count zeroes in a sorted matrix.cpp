#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	
	int arr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	
	int j = m-1;
	int i = 0;
	
	
	int zc = 0;
	while(i < n && j >= 0){
		while(arr[i][j] == 1 && j >= 0){
			j--;
		}
		
		while(arr[i][j] == 0 && i < n){
			i++;
			zc += j + 1;	
		}
	}
	
	cout<<zc<<endl;
	
	return 0;
}

