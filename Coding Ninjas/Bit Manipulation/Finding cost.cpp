#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    int i=0,k=0;
    int cost=0;
    int j=0;
    int l=0;
  	while(i<n){
        //Traversing until i found 1
        while(s[i]!='1' && i<n){
            l=1;
            k=1;
            i++;
        }
        if(i==n){
            break;
        }
        if(i<n){
        	j=i+1;
            //Traversing until i found zero::
        	while(s[j]!='0' && j<n){
				j++;	
        	}
            //If the last position was 1::I will set k=0 Beacause i don't have to add x now::
            if(j==n){
                k=0;
            }
        	if(k==1){
            	cost=cost+x;
        	}
        	i=j;
        	k=0;
        }
    }
    //If there was 0 anywhere in the string then i have to add y ::
    if(l==1){
       cost=cost+y; 
    }
    cout<<cost;
	return 0;
}

