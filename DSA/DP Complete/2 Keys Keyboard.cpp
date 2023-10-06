#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int res = 0;
    for(int i=2;i*i<=n;){
        if(n%i == 0){
            res += i;
            n /= i;
        }else{
            i++;
        }
    }
    
    if(n != 1)
        res += n;
    
    cout<<res;
    return 0;
}
