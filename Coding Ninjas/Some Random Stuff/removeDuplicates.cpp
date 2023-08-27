
#include<bits/stdc++.h>
using namespace std;

void removeDuplicate(string str, int n) ;

int main()
{ 
   string str;
   cin>>str;
   int n;
   n=str.length();
   removeDuplicate(str,n); 
   return 0; 
} 

void removeDuplicate(string str, int n)
{ 
    
    set<char> s;
    for(int i=0;i<n;i++){
        s.insert(str[i]);
    }
  
     
    int i = 0; 
    for (auto x : s) 
       str[i++] = x; 
    str[i] = '\0'; 
  
    cout<<str; 
} 
