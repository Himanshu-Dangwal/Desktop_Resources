//Maximum Consecutive Ones When k flips are allowed
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){

	string arr;
	
	cin>>arr;
	
	int k;
	cin>>k;
	int j = -1;
	int count = 0;
	int ans = 0;
	for(int i=0;i<arr.length();i++){
		
		if(arr[i] == '0'){
			count++;
		}
		
		while(count > k){
			j++;
			if(arr[j] == '0'){
				count--;
			}
		}
		int pans = i - j;
		if(pans > ans){
			ans = pans;
		}
	}
	cout<<"\nMax Consecutive One's Possible are : ";
	cout<<ans<<endl;
	
	return 0;
}

