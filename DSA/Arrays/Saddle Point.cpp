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
	
	arr[n][m];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		int mtn = arr[i][0];
		int mIdx = 0;
		for(int j=1;j<m;j++){
			if(arr[i][j] < mtn){
				mtn = arr[i][j];
				mIdx = j;
			}
		}
		int maxTN = arr[i][mIdx];
		bool flag = true;
		for(int k = 0;k<n;k++){
			if(arr[mIdx][k] > arr[i][mIdx]){
				flag = false;
			}
		}
		if(flag){
			cout<<arr[i][mIdx]<<endl;
			return 0;
		}
	}

	return 0;
}

