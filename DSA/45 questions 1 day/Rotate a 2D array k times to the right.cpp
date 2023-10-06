//Rotate a 2D array k times to the right::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){

	int n,m;
	cin>>n>>m;
	
	int arr[n][m];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	
	int k;
	cin>>k;
	//In case k is greter than
	k = k%m;
	
	for(int i=0;i<n;i++){
		int current_row = i;
		int start = m-k;
		
		int temp[m];
		int c=0;
		for(int j=m-k;j<m;j++){
			temp[c++] = arr[current_row][j];
		}
		
		for(int j=0;j<m-k;j++){
			temp[c++] = arr[current_row][j];
		}
		
		for(int j=0;j<m;j++){
			arr[current_row][j] = temp[j];
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

