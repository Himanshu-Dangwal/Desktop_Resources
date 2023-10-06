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
	
	int key;
	cin>>key;
	bool ans = false;
	for(int i=0;i<n;i++){
		if(key >= arr[i][0] && key <= arr[i][m-1]){
			//binary search
			int start = 0;
			int end = m;
			while(start < end){
				
				if(start == end){
					if(arr[i][start] != key){
						break;
					}
				}
				
				int mid = (start + end)/2;
				if(arr[i][mid] == key){
					ans = true;
					break;
				}else if(arr[i][mid] > key){
					end = mid - 1;
				}else{
					start = mid + 1;
				}
			}
		}
	}
	
	if(ans){
		cout<<"True";
	}else{
		cout<<"False";
	}
	return 0;
}

