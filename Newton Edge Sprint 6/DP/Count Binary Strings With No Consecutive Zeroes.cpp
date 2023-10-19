#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int ending_at_zeroes = 1;
    int ending_at_ones = 1;

    for(int i=2;i<=n;i++){
        int new_zeroes = ending_at_ones;
        int new_ones = ending_at_zeroes + ending_at_ones;

        ending_at_zeroes = new_zeroes;
        ending_at_ones = new_ones;
    }


    int ans = ending_at_zeroes + ending_at_ones;
    cout<<ans;
}