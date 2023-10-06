
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
//#define int long long
int main() {
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n,m;
	    cin>>n>>m;
	vector<pair<ll,ll>> v;
	for(int i=0;i<n;i++){
	    int c,d;
	    cin>>c>>d;
	  v.push_back(make_pair(c,d));
	}

	long long a[m];
	for(int i=0;i<m;i++)
	{
	 cin>>a[i];
	}


	 sort(v.begin(),v.end());

//	 helper(v,a,m,n);

		
	for(int i=0;i<m;i++)
	{
		int current=a[i];
		int pos=lower_bound(v.begin(),v.end(),make_pair(current,0))-v.begin();
		
		if(pos==0)
		cout<<v[0].first-current<<endl;
		
		else
		{
			int ans=-1;
		 	if(v[pos-1].second>current)
		    {
		        ans=0;
		    }
		
		else if(pos<v.size())
		{
		    ans=v[pos].first-current;
		}
		
		    cout<<ans<<endl;
		}
	
	
	
	}


	}
	return 0;
}
