//Efficient approach for same parity::
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
	int oc = 0;
	int ec = 0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]%2 == 0)
			ec++;
		else
			oc++;	
	}
	
	int ans = ec*(ec-1)  +  oc*(oc-1);
	ans = ans/2;
	
	cout<<ans<<endl;
	
	return 0;
}

