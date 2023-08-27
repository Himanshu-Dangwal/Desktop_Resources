#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int n,i;
    cin>>n;
    int at[n];
    int dt[n];
    for(i=0;i<n;i++){
        cin>>at[i];
    }
    for(i=0;i<n;i++){
        cin>>dt[i];
    }
    
      pair<int,int> pairt[n]; 
  
   
    for (i = 0; i < n; i++)  
    { 
        pairt[i].first = at[i]; 
        pairt[i].second =dt[i]; 
    } 
  
     
    sort(pairt, pairt + n); 
      
   
    for (int i = 0; i < n; i++)  
    { 
        at[i] = pairt[i].first; 
        dt[i] = pairt[i].second; 
    }
   int count=0; 
   int chair=0;
    int j;
    int total_men=0;
    int men=0;
    int p;
    int l;
    for(i=0;i<n;i++){
    	if(i==0){
			chair+=1;
            total_men+=1;
        	men=total_men;
            count=dt[i];
            continue;
        }
        if(at[i]<count){
			total_men+=1;
            men=total_men;
        }
        else{
            l=0;
            men++;
            for(j=0;j<i;j++){
				if(at[i]>dt[j]){
                    l++;
                }
            }
            p=men-l;
            if(p>total_men){
                total_men++;
            }
        }
        if(dt[i]<count){
            count=dt[i];
        }
    }
    chair=total_men;
    cout<<chair;  
}
