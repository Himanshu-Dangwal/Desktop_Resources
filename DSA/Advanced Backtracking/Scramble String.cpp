//Scramble String::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

bool isScramble(string s1,string s2){
	
	if(s1.length() != s2.length()) return false;
	
	
//	cout<<s1<<" "<<s2<<endl;
	
	if(s1.length() == 1 && s1 != s2){
		return false;
	}
	
	if(s1 == s2){
		return true;
	}
	
	for(int i=1;i<=s1.length()-1;i++){
		if((isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i)))  || 
			(isScramble(s1.substr(0,i),s2.substr(s2.length()-i)) && isScramble(s1.substr(i),s2.substr(0,s2.length()-i)))){
			return true;
		}
	}
	return false;
}


bool isScramble2(string s1,string s2,int si1,int ei1,int si2,int ei2){
	
	if(ei1-si1 != ei2-si2){
		return false;
	}
	
//	cout<<s1.substr(si1,ei1-si1+1)<<" "<<s2.substr(ei1-si1+1)<<endl;
	
	
	if(s1.substr(si1,ei1-si1+1) == s2.substr(si2,ei2-si2+1)) return true;
	
	for(int i=0;i<ei1-si1;i++){
		
		if((isScramble2(s1,s2,si1,si1+i,si2,si2+i) && isScramble2(s1,s2,si1+i+1,ei1,si2+i+1,ei2))  || 
		   (isScramble2(s1,s2,si1,si1+i,ei2-i,ei2) && isScramble2(s1,s2,si1+i+1,ei1,si2,ei2-i-1))){
		   	return true;
		   }
		
	}
	return false;
	
}

int main(){
	string s1,s2;
	cin>>s1>>s2;
	
	cout<<isScramble(s1,s2)<<endl;
	cout<<isScramble2(s1,s2,0,s1.length()-1,0,s2.length()-1)<<endl;
	return 0;

	return 0;
}

