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
	
	for(int i=0;i<n;i++){
		for(int j=i;j<m;j++){
			int temp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = temp;
		}
	}
	cout<<endl;
	
	for(int i=0;i<n;i++){
		int l = 0;
		int r = m-1;
		
		while(l < r){
			int temp = arr[i][l];
			arr[i][l] = arr[i][r];
			arr[i][r] = temp;
			l++;
			r--;
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

