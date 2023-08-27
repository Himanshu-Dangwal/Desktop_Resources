#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;

//Approach 1:::O(n*sqrt(n))
// bool checkPrime(int n){
//     int val = sqrt(n);
//     for(int j=2;j<=val;j++){
//         if(n%j==0)
//             return 0;
//     }
//     return 1;
// }

// int main(){
//     int n;
//     cin>>n;
//     int count = 1;
//     for(int i=3;i<=n;i++){
//         if(checkPrime(i))
//             count++;
//     }
//     if(n == 1){
//         cout<<0<<endl;
//     }else{
//     	cout<<count<<endl;
//     }
// }

//Using sieve of erasthothenes:::
//Time COmplexity  = O(N(log(log(sqrt(n)))))::
int main(){
    int n;
    cin>>n;
    bool arr[n+1];
    memset(arr,1,sizeof(arr));
    arr[0] = arr[1] = false;
    for(int i=2;i<=(sqrt(n));i++){
        if(arr[i]){
            for(int j=i*i;j<=n;j+=i){
                arr[j] = false;
            }
        }
    }
    int count = 0;
    for(int i=2;i<=n;i++){
        if(arr[i])
            count++;
    }
    cout<<count<<endl;
}


