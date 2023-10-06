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
	
	int key;
	cin>>key;
	
	int start = 0;
	int end = n-1;
	int ans = -1;
	while(start <= end){
		int mid = (start + end)/2;
		
		if(arr[mid] == key){
			ans = mid;
			break;
		}else if(arr[mid] > key){
			end = mid;
		}else{
			start = mid;
		}
	}
	start = 0;
	
	if(arr[ans - 1] == key){
//		search(left)
		int end = ans;
		while(start < end){
			int mid = (start + end)/2;
			if(arr[mid] == key){
				ans = mid;
				end = mid - 1;
			}else{
				start = mid + 1;
			}
		} 
	}
	cout<<ans<<endl;
	return 0;
}

