#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
 ios_base::sync_with_stdio(false);
cin.tie(NULL);
int m,p,n,q,k;
cin>>m>>p>>q>>n>>k;
int dp[n+1][k+1];
for(int i=0;i<=n;i++)
for(int j=0;j<=k;j++)
dp[i][j]=LLONG_MAX;
for(int i=0;i<=k;i++)
dp[0][i]=0;
for(int i=1;i<=n;i++)
dp[i][0]=m+dp[i-1][0];
k=min(k,n-1);
for(int i=1;i<=k;i++)
{
    for(int j=1;j<=n;j++)
    {
        dp[j][i]=min(dp[j][i],dp[j-1][i]+m);
        int pass=dp[j][i-1]+p;
        for(int k=j*2;k<=n;k+=j)
        {
            dp[k][i]=min(dp[k][i],pass+q);
            pass+=q;
        }
    }
}
int ans=dp[n][0];
for(int i=1;i<=k;i++)
{
    ans=min(ans,dp[n][i]);
}
cout<<ans;
 return 0;
}
/* 1 4 2 20 20 */