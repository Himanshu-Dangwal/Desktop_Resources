#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mod 1000000007
typedef long long ll;

ll power(int x,int y)
{
    ll res = 1; 
 
    while (y > 0) {
        if (y & 1)
            res = (res%mod * x%mod)%mod;
 
        y = y >> 1; 
        x = (x%mod * x%mod)%mod; 
    }
    return (res%mod+mod)%mod;
}

int main(){
	int n;
	cin>>n;
	
	unordered_map<int,int> mp;
	int arr[n];
	
	int less = 0;
	int greater = 0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		mp[arr[i]]++;
		
		if(arr[i] < 0) less++;
		if(arr[i] > 0) greater++;
	}
	
	
	
	ll cnt = 0;
	if(mp.find(0) == mp.end()){
		cout<<0;
	}else{
		
		int cz = mp[0];
		ll cnt1 = power(2,less)%mod - 1;
		ll cnt2 = power(2,greater)%mod - 1;
		ll cnt3 = power(2,cz)%mod - 1;
		cnt = (((cnt3%mod*cnt1%mod)+mod)%mod+ ((cnt3%mod*cnt2%mod)+mod)%mod)%mod;
		cnt = (cnt%mod + cnt3%mod)%mod;
		cout<<cnt;
		
	}
	return 0;
}

