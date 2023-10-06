//Moore's Voting Algorthm to find majority element
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;cin>>arr[i++]);
	
	int count = 0;
	int candidate = 0;
	
	for(int i=0;i<n;i++){
		if(count == 0){
			candidate = arr[i];
		}
		
		if(arr[i] == candidate){
			count += 1;
		}else{
			count -= 1;
		}
	}
	cout<<candidate<<endl;

	return 0;
}

