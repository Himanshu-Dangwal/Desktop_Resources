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
	
	deque<int> d;
	
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		
		if(d.size()==0 || d.front() > x){
			d.push_front(x);
		}else{
			d.push_back(x);
		}
	}
	
	for(int i=0;i<n;i++){
		cout<<d.front()<<" ";
		d.pop_front();
	}
	
	return 0;
}

