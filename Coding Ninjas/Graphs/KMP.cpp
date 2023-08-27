//KMP Algorithm and Code
#include<bits/stdc++.h>
using namespace std;

int* getLPS(string pattern){
	int patternLen = pattern.length();
	int *lps = new int[patternLen];
	int i=1;
	int j=0;
	lps[0] = 0;
	while(i<patternLen){
		if(pattern[i] == pattern[j]){
			pattern[i] == j+1;
			i++;
			j++;	
		}else{
			if(j!=0){
				j = lps[j-1];
			}else{
				lps[i] = 0;
				i++;
			}
		}
	} 
	return lps;
}

bool getKMP(string text,string pattern){    //We have to search for the pattern in the string in the text::
	int lenText = text.length();
	int lenPattern = pattern.length();
	
	int *lps = getLPS(pattern);
	int i=0;
	int j=0;
	while(i<lenText && j<lenPattern){
		if(pattern[j] == text[i]){
			i++;
			j++;
		}else{
			if(j!=0){
				j = lps[j-1];
			}else{
				i++;
			}
		}
	}
	if(j == lenPattern){
		return true;
	}
	return false;
}

int main(){
	string text,pattern;
	cin>>text>>pattern;
	
	cout<<getKMP(text,pattern);
}
