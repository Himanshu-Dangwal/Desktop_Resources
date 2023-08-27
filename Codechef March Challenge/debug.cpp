#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<pair<int,pair<int,int>>> viii;
viii kruskal(viii g,int V)
{
    viii res;
    int s,d,w;
    int a[V];
    for(int i=0;i<V;i++)
    {
        a[i]=-1;
    }
    sort(g.begin(),g.end());
    int e=g.size();
    for(int i=0;i<e;i++)
    {
        s=g[i].second.first;
        d=g[i].second.second;
        w=g[i].first;
        if(find(s,a)!=find(d ,a))
        {
            res.push_back(g[i]);
            unionByWeight(s, d, a);
        }
    }
    return res;
}
int main()
{
	viii g,res;
	int V,s,d,e,w;
	cin>>V;
	cin>>e;
	for(int i=0;i<e;i++)	
	{
    	cin>>s>>d>>w;
    	g.push_back(make_pair(w,make_pair(s,d)));
	}
	res=kruskal(g,V);
	int sum=0;
	for(int i=0;i<res.size();i++)
	{
    	int wt=res[i].first;
    	cout<<res[i].second.first<<" "<<res[i].second.second<<endl;
    	sum=sum+wt;
	}
    return 0;
}
