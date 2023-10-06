//Count all subarrays with 0 sum::
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
	for(int i=0;i<n;cin>>arr[i++]);
	
	unordered_map<int,int> m;
	
	m[0] = 1;
	
	int ans = 0;
	int sum = 0;
	
	for(int i=0;i<n;i++){
		sum += arr[i];
		if(m.find(sum) != m.end()){
			ans += m[sum];
			m[sum]++;
//			cout<<sum<<endl;
		}else{
			m[sum]++;
		}
			
	}
	
	cout<<ans;
	
	return 0;
}

