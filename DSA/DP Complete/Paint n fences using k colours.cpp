 //Paint n fence using 3 colours such that no more than 2 consecutive frnces have same colours:: 
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
	int k;
	cin>>k;
	
	int l2s = k;                 //last 2 same::
	int l2d = k*(k-1);			 //Last 2 differnt::
	int total = l2s + l2d;       //Total::
	
	for(int i=3;i<=n;i++){
		l2s = l2d;
		l2d = total * (k-1);
		
		total = l2s + l2d;
	}
	
	cout<<total<<endl;
	return 0;
}

