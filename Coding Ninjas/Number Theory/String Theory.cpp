//KMP Code:::
//To find if apattern is present in a string s or not::

//#include<bits/stdc++.h>
//using namespace std;
//
//int* getLPS(string pattern){
//	int *lps = new int[pattern.length()];
//	lps[0] = 0;
//	int j = 0;
//	int i =1;
//	while(i<pattern.length()){
//		if(pattern[i] == pattern[j]){
//			lps[i] = j+1;
//			i++;
//			j++;
//		}else{
//			if(j!=0){
//				j = lps[j-1];
//			}else{
//				lps[i] = 0;
//				i++;
//			}
//		}
//	}
//	return lps;
//}
//
//void kmp(string s,string pattern){
//	int len_s = s.length();
//	int len_p = pattern.length();
//	int *lps = new int[len_p];
//	lps = getLPS(pattern);
//	int i=0;
//	int j=0;
//	while(i < len_s && j < len_p){
//		if(s[i] == pattern[j]){
//			i++;
//			j++;
//		}
//		else{
//			if(j!=0){
//				j = lps[j-1];
//			}else{
//				i++;
//			}
//		}
//	}
//	if(j == len_p){
//		cout<<"true"<<endl;
//	}else{
//		cout<<"false"<<endl;	
//	}
//	return;
//}
//
//int main(){
//	string s,pattern;
//	cin>>s>>pattern;
//	kmp(s,pattern);
//}


//Z Algorithm:::
#include<bits/stdc++.h>
using namespace std;

void Zalgo(string str,int *z){
	int n = str.length();
	z[0] = 0;
	int l=0,r=0;
	for(int i=1;i<n;i++){
		if(i>r){
			l=i;
			r=i;
			while(r<n && str[r-l]==str[r]){
				r++;
			}
			z[i] = r-l;
			r--;
		}else{
			int k = i-l;
			if(z[k]+i <=r){
				z[i] = z[k];
			}else{
				l = i;
				while(r<n && str[r-l] == str[r]){
					r++;
				}
				z[i] = r-l;
				r--;
			}
		}
	}
	return;
}

void search(string s,string pattern){
	string str = pattern + '$' + s;
	int len_str = str.length();
	int *z = new int[len_str]();
	Zalgo(str,z);
	int k =0;
	for(int i=pattern.length()+1;i<len_str;i++){
		if(z[i] == pattern.length()){
			cout<<"Found"<<endl;
			k=1;
			break;
		}
	}
	if(k==0){
		cout<<"Not Found"<<endl;
	}
	return;
}

int main(){
	string s,pattern;
	cin>>s>>pattern;
	search(s,pattern);
	return 0;
}


































