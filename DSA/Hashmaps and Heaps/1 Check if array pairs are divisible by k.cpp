//Check if array pairs are divisible by k::
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
	
	unordered_map<int,int> mp;
	
	for(int i=0;i<n;i++){
		int rem = arr[i]%k;
		mp[rem]++;
	}
	
	int flag = 1;
	
	for(int i=1;i<k;i++){
		if(mp[i] != mp[k-i]){
			cout<<i<<" ";
			flag = 0;
			break;
		}
	}
	
	if(mp.find(0) != mp.end()){
		int value = mp[0];
		if(value%2 != 0){
			flag = 0;
		}
	}
	
	if(k%2 == 0){
		int value = k/2;
		if(mp.find(value) != mp.end()){
			if(mp[value]%2 != 0){
				flag = 0;
			}
		}
	}
	
	
	if(flag == 1){
		cout<<"Yes Possible";
	}else{
		cout<<"Not Possible";
	}

	return 0;
}

