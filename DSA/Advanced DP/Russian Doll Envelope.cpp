 //Russian Doll Envelop::

//Approach :: 
//	Width ke basis pe sort and height ke basis pe LIS
	
	

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
	
	
struct Pair{
	int w;
	int h;
};

bool compare(Pair x,Pair y){
    if(x.w != y.w)
	    return x.w < y.w;
	
	return x.h < y.h;    
}

int main(){
	int n;
	cin>>n;
	
	Pair p[n];
	for(int i=0;i<n;i++){
		cin>>p[i].w>>p[i].h;
	}
	
	sort(p,p+n,compare);
	int dp[n];
	
	int omax = 0;
//	cout<<"HEre"<endl;
	for(int i=0;i<n;i++){
		int max = 0;
//		cout<<"Inside"<<endl;
		for(int j=0;j<i;j++){
			if((p[j].h < p[i].h)  && (p[j].w < p[i].w)){
				if(dp[j] > max){
					max = dp[j];
				}
			}
		}
		dp[i] = max + 1;
//		cout<<dp[i]<<" "<<endl;
		if(omax < dp[i])
			omax = dp[i];
	}

	cout<<omax;
	
	return 0;
}

