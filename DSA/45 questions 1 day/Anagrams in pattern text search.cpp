//Given an input string and a pattern.Print all the start indices from where the anagram of given pattern matches::

//Method used :: Sliding Window
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
#define MAX 256

bool check(char countP[],char countT[]){
	for(int i=0;i<MAX;i++){
		if(countP[i] != countT[i])
			return false;
	}
	return true;
}

int main(){
	string text,pattern;
	cin>>text>>pattern;
	
	int psize = pattern.length();
	int tsize = text.length();
	
	char countP[MAX] = {0};
	char countT[MAX] = {0};
	
	for(int i=0;i<psize;i++){
		countP[pattern[i]]++;
		countT[text[i]]++;
	}	
	
	for(int i=psize;i<tsize;i++){
		
		if(check(countP,countT)){
			cout<<i-psize<<" ";
		}
		
		countT[text[i]]++;
		countT[text[i-psize]]--;
		
	}
	if(check(countP,countT))
		cout<<tsize-psize<<endl;
	
	return 0;
}

