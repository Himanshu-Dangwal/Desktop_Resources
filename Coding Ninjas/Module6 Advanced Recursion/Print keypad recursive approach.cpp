/*Print Keypad Combinations Code
Send Feedback
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
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

void print(int num,string output){
    if((num/10)==0){
        int count_add=num%10;
        int x=s[count_add].size();
        for(int i=0;i<x;i++){
            cout<<s[count_add][i]+output<<endl;
        }
        return;
    }
    int k = num%10;
    int r=num/10;
    int count = s[k].size();
    for(int i=0;i<count;i++){
        print(r,s[k][i]+output);
    }
	
    return;
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    string output = "";
    print(num,output);
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}

