//Z Algorithm::

#include<bits/stdc++.h>
using namespace std;

void zAlgorithm(int *z,string final){
	int l = 0;
	int r = 0;
	z[0] = 0;
	int n = final.length();
	for(int i=1;i<n;i++){
		if(i>r){
			l = i;
			r = i;
			while(r<n && final[r-l] == final[r]){
				r++;
			}
			z[i] = r-l;
			r--;
		}else{
			int k = i-l;
			if(z[k]<=r-i){
				z[i] = z[k];
			}else{
				l = i;
				while(r<n && final[r-l] == final[r]){
					r++;
				}
				z[i] = r-l-1;
				r--;
			}
		}
	}
} 

bool search(string text,string pattern){
	string final = pattern+"$"+text;
	int n = final.length();
	int *z = new int[n];
	zAlgorithm(z,final);
	int k = 1;
	for(int i=0;i<n;i++){
		if(z[i] == pattern.length()){
			cout<<"Index = "<<i-pattern.length()-1;
			k=0;
//			return true;
		}
	}
	if(k==0)
		return true;
	return false;
}

int main(){
	string text,pattern;
	cin>>text>>pattern;
	cout<<search(text,pattern)<<endl;;
	return 0;
}
