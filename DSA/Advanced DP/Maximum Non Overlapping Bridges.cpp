 //Maximum Non Overlapping Bridges::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

struct Pair{
	int x,y;
};


bool compare(Pair a,Pair b){
//	return a.x < b.x;
	if(a.x != b.x)
		return a.x < b.x;
	else
		return a.y < b.y;	
}

int main(){
	int n;
	cin>>n;
	
	Pair p[n];
	
	for(int i=0;i<n;i++){
		cin>>p[i].x>>p[i].y;
	}
	
	sort(p,p+n,compare);
	
	int dp[n];
	
	int omax = 0;
	
	for(int i=0;i<n;i++){
		int max = 0;
		for(int j=0;j<i;j++){
			if(p[i].y >= p[j].y){
				if(dp[j] > max){
					max = dp[j];
				}
			}
		}
		dp[i] = max + 1;
		if(dp[i] > omax){
			omax = dp[i];
		}
	}
	
	cout<<omax<<endl;
	return 0;
}

