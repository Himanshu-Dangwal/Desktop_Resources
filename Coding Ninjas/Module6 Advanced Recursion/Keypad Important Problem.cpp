//Return Keypad Code::

/*Return Keypad Code
Send Feedback
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the
 count of elements populated in the output array.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/
#include<bits/stdc++.h>
using namespace std;

string s[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int helper(int n,string output[]){
	if(n==0){
		output[0]="";
		return 1;
	}
	int index = n%10;
	int smallAns = helper(n/10,output);
	int copies = s[index].size()-1;
	int f=smallAns;
	while(copies--){
		for(int i=0;i<smallAns;i++){
			output[f++]=output[i];
		}
	}
	int length=s[index].size();
	int k=0;
	for(int i=0;i<length;i++){
		int r=smallAns;
		while(r--){
			output[k]=output[k] + s[index][i];
			k++;
		}
	}
	return smallAns*length;
}

int keypad(int n,string output[]){
	if(n==0 || n==1){
		return -1;
	}
	int num = helper(n,output);
}

int main(){
	int n;
	cin>>n;
	string output[10000];
	int count = keypad(n,output);
	cout<<count<<endl;
	for(int i=0;i<count;i++){
		cout<<output[i]<<endl;
	}
	return 0;
}


/* 23
		2 abc
		3 def
		
		n/10 - 3
		n%10 - will give me value-string that i will use::
		 3 'd' 'e' 'f'
		 2  'ad' 'ae' af 
		 copies and then concatenate::
*/		 
		 
