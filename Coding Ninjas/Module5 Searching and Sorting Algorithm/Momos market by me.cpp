/*Momos Market
Send Feedback
Shreya loves to eat momos. Her mother gives her money to buy vegetables but she manages to save
 some money out of it daily. After buying vegetables, she goes to "Momos Market", where there are 
 ‘n’ number of shops of momos. Each of the shops of momos has a rate per momo. She visits the market 
 and starts buying momos (one from each shop) starting from the first shop. She will visit the market 
 for ‘q’ days. You have to tell that how many momos she can buy each day if she starts buying from
  the first shop daily. She cannot use the remaining money of one day on some other day. But she 
  will save them for other expenses in the future, so, you also need to tell the sum of money left with her at the end of each day.
Input Format:
First line will have an integer ‘n’ denoting the number of shops in market.
Next line will have ‘n’ numbers denoting the price of one momo of each shop.
Next line will have an integer ‘q’ denoting the number of days she will visit the market.
Next ‘q’ lines will have one integer ‘X’ denoting the money she saved after buying vegetables.
Constraints:
1 <= n <= 10^5
1 <= q <= 10^5
1 <= X <= 10^9
Output:
There will be ‘q’ lines of output each having two space separated integers denoting number of momos 
she can buy and amount of money she saved each day.
Sample Input:
4
2 1 6 3
1
11
Sample Output:
3 2
Explanation:
Shreya visits the "Momos Market" for only one day. She has 11 INR to spend. She can buy 3 momos, each from the first 3 shops. She would 9 INR (2 + 1 + 6) for the same and hence, she will save 2 INR.
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll search(ll prefix_sum[],ll money,ll n){
    ll start = 0;
    ll end = n-1;
    ll index;
  	if(money>prefix_sum[end]){
        return end;
    }
    if(money<prefix_sum[0]){
        return -1;
    }
    else{
        while(start<=end){
            ll mid = (start+end)/2;
            if(prefix_sum[mid]== money){
                return mid;
            }if(prefix_sum[mid]<money){
                index=mid;
                start=mid+1;
            }if(prefix_sum[mid]>money){
                index=mid-1;
                end=mid-1;
            }
        }
    }
    return index;
}

/*
		2 9 12
        8
        1 11 23
        start = 0;
        end = 2;
        mid =1;
        



*/
int main(){
	ll n;
    cin>>n;
    ll shops[n];
    for(ll i=0;i<n;i++){
        cin>>shops[i];
    }
    ll prefix_sum[n];
    ll sum=0;
    for(ll i=0;i<n;i++){
        sum+=shops[i];
        prefix_sum[i]=sum;
    }
    ll q;
    cin>>q;
    ll r=q;
    ll money;
    vector<pair<ll,ll>> saved_money;
    while(r--){
        cin>>money;
        ll index = search(prefix_sum,money,n);
        if(index==-1){
            saved_money.push_back(make_pair(index+1,money));
        }else{
        saved_money.push_back(make_pair(index+1,(money-prefix_sum[index])));}
    }
   
	for(ll i=0;i<q;i++){
		cout<<saved_money[i].first<<" "<<saved_money[i].second<<endl;
    }
}   
    
    
    
