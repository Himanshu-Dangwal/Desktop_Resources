//Consecutive One's
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
	
	int k;
	cin>>k;
	
	int count = 0;
	int ans = 0;
	int j = -1;
	
	for(int i=0;i<n;i++){
		if(arr[i] == 0){
			count++;
		}
		
		while(count > k){
			j++;
			if(arr[j] == 0){
				count--;
			}		
		}
		int pans = i - j;
		if(pans > ans){
			ans = pans;
		}
		
	}
	
	cout<<ans<<endl;
	return 0;
}

