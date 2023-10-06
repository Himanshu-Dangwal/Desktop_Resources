//BOOLEAN PARANTHESIAZATION::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;


int boolean_parenthesiazation(string s1,string s2){
	
	int n = s1.length();
	
	int dpt[n][n];
	int dpf[n][n];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dpt[i][j] = 0;
			dpf[i][j] = 0;
		}
	}	
	
	
	for(int g=0;g<n;g++){
		for(int i=0,j=g;j<n;i++,j++){
			
			if(g == 0){
				if(s1[i] == 'T'){
					dpt[i][j] = 1;
					dpf[i][j] = 0;
				}else{
					dpt[i][j] = 0;
					dpf[i][j] = 1;
				}
			}else{
				
				for(int k=i;k<j;k++){
					
					int ltc = dpt[i][k];
					int rtc = dpt[k+1][j];
					int lfc = dpf[i][k];
					int rfc = dpf[k+1][j];
					
					
					char op = s2[k];
					
					if(op == '|'){
						dpt[i][j] += ltc*rtc + lfc*rtc + ltc*rfc;
						dpf[i][j] += lfc*rfc;
					}else if(op == '&'){
						dpt[i][j] += ltc * rtc;
						dpf[i][j] += ltc*rfc + lfc*rtc + lfc*rfc;
					}else{ // XOR ^
						dpt[i][j] += ltc*rfc + rtc * lfc;
						dpf[i][j] += ltc*rtc + lfc * rfc;
					}
					
				}
				
			}
			
			
		}
	}
//	
//	cout<<"\nDP True Table"<<endl;
//	
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			cout<<dpt[i][j]<<"                        ";
//		}
//		cout<<endl;
//	}
//	
//	cout<<"\nDP False Table"<<endl;
//	
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			cout<<dpf[i][j]<<"                        ";
//		}
//		cout<<endl;
//	}
	
	return dpt[0][n-1];
	
}

int main(){
	
	string s1,s2;
	cin>>s1>>s2;
	
//	s1 consists of T/F
//	s2 consists of operators 	
	cout<<boolean_parenthesiazation(s1,s2)<<endl;

	return 0;
}

