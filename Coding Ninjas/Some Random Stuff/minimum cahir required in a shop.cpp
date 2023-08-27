#include<bits/stdc++.h>
#include<utility>
#include<algorithm>
using namespace std;
int main() 
{
    int n,i,tempChair,maxChair;
    tempChair=0;
    maxChair=0;
    int x=0;
    cin>>n;
    int a1[n];
    int a2[n];
    for(i=0;i<n;i++)
    {
        cin>>a1[i];
    }
    cout<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a2[i];
    }
    cout<<endl;
    pair<int ,char>p1[2*n];
    for(i=0;i<2*n;i++)
    {
        if(i<n)
            p1[i]=make_pair(a1[i],'S');
        else
        {
            p1[i]=make_pair(a2[x++],'E');
        }
            
    }
    sort(p1,p1+2*n);
    for(i=0;i<2*n;i++)
    {
        if(p1[i].second=='S')
        {
            tempChair++;
        }
        else
        {
            tempChair--;
        }
        if(tempChair>maxChair)
        {
            maxChair=tempChair;
        }
        
    }
    
    cout<<maxChair<<endl;
    
    return 0;

}
