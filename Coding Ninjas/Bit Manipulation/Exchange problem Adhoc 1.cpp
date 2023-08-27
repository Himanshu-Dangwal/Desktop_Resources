/*  Exchange Problem codeforces::
	We have to make the first string(bit set) equals to the second string (bit set)::
		
		we can perform 2 operations 
		1> swap swapping ith bit with jth bit will cost |i-j|
		2> flip the bit it will cost 1::
			
	We have to minimize the cost
*/	

#include<bits/stdc++.h>
using namespace std;

int main(){
	string s,t;
	cin>>s>>t;
	char k;
	int count=0;
	int n = s.length();
	
	for(int i=0;i<n;){
		if(s[i]==t[i])
		{
			i++;
			continue;
		}
		if(i==n-1 && s[i]!=t[i]){
			count++;
			break;
		}
		else{
			if(s[i+1]!=t[i+1] && s[i]!=s[i+1]){
				i+=2;
				count++;		
			}else{
				count++;
				i++;
			}
		}	
	}
	cout<<count;
}		
