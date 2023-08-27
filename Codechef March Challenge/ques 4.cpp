#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	int N,E,H,A,B,C;
	int max_items = 0;
	int add_on = 0;
	int price = 0;
	while(t--){
		cin>>N>>E>>H>>A>>B>>C;
		if(C<A && C<<B){
			if(E<H){
				max_items+=E;
				price+=max_items*C;
				if(!check(max_items,N)){
					add_on+=(H-E)/3;
					price+=add_on*B;
					max_items+=add_on;
				}
			}else{
				max_items+=H;
				price+=max_items*C;
				if(!check(max_items,N)){
				add_on+=(E-H)/2;
				price+=add_on*A;
				max_items+=add_on;}
			}
		}
		if(A<C && A<B){
			if(B<C){
				max_items+=E/2;
				E=ceil(E/2);
				price+=max_items*A;
				if(!check(max_items,N)){
				add_on+=H/3;
				H=ceil(H/3);
				max_items+=add_on;
				price+=add_on*B;}
				if(!check(max_items,N)){
				if(E>0 && H>0){
					max_items+=1;
					price+=C;
				}}
			}
			else{
				max_items+=E/2;
				E=ceil(E/2);
				price+=max_items*A;
				if(!check(max_items,N))
				{
				if(E<H){
					max_items+=E;
					price+=max_items*C;
					add_on+=(H-E)/3;
					price+=add_on*B;
					max_items+=add_on;
				}else{
					max_items+=H;
					price+=max_items*C;
					add_on+=(E-H)/2;
					price+=add_on*A;
					max_items+=add_on;
				}
			}
			}
		}
		if(B<C && B<A){
			if(A<C){
				max_items+=H/3;
				H=ceil(H/2);
				price+=max_items*B;
				if(!check(max_items,N))
				{
				add_on+=E/2;
				E=ceil(E/2);
				max_items+=add_on;
				price+=add_on*A;
			}
				if(!check(max_items,N)){
				
				if(E>0 && H>0){
					max_items+=1;
					price+=C;
				}}
			}
			else{
				max_items+=H/3;
				H=ceil(H/3);
				price+=max_items*B;
				
				if(!check(max_items,N))
				{
				if(E<H){
					max_items+=E;
					price+=max_items*C;
					add_on+=(H-E)/3;
					price+=add_on*B;
					max_items+=add_on;
				}else{
					max_items+=H;
					price+=max_items*C;
					add_on+=(E-H)/2;
					price+=add_on*A;
					max_items+=add_on;
				}
			}
			}
		}
	}
}
