//778 116

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mod 1000000007
typedef long long ll;


int nCr(int n, int r){
        
        if(r > n) return 0;
        if(r == n) return 1;
        int ans = 1;
        for(int i=0;i<r;i++){
            ans = (ans%mod * (n-i)%mod)%mod;
            ans = ans/(i+1);
            ans = ans%mod;
        }
    	if(ans < 0) return (ans+mod)%mod;
        return ans;
	

}

int main(){
	int n,r;
	cin>>n>>r;
	cout<<nCr(n,r);

	return 0;
}

