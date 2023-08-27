//Subsequences of a string
#include<bits/stdc++.h.>
using namespace std;

int getSubsequences(string input,string output[]){
	if(input.empty()){
		output[0]="";
		return 1;
	}
		string smallString = input.substr(1);
		int smallAns = getSubsequences(smallString,output);
		for(int i=0;i<smallAns;i++){
			output[i+smallAns] = input[0] + output[i];
		}
	return 2*smallAns;
}

int main(){
	string input;
	cin>>input;
	int n=input.size();
	int len = pow(2,n);
	string* output = new string[len];
	int count = getSubsequences(input,output);
	for(int i=0;i<count;i++){
		cout<<output[i]<<endl;
	}
	return 0;
}
