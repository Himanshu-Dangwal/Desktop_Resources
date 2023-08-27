#include <iostream>
#include <string>
#include<map>
using namespace std;



string uniqueChar(string str)
{ 
    string k;
    int u=0;
	map<char,int> m;
    for(int i=0;i<str.length();i++){
       m[str[i]]++;
        if(m[str[i]]==1){
            k=k+str[i];
        }
   }
	return k;
} 

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}




