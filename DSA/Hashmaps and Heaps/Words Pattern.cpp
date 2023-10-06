#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1,s2;
    cin>>s1;
    
    fflush(stdin);
    
    getline(cin,s2);
//	cin.getline(s2);    
    vector<string> words;
    
    stringstream s(s2);
    string word;
    while(s >> word){
        words.push_back(word);
    }
    
//    for(int i=0;i<words.size();i++){
//    	cout<<words[i]<<" ";
//	}
//	cout<<endl;
    
    unordered_map<char,string> m;
    unordered_map<string,bool> map2;
    
    
    int j = 0;
    
    for(int i=0;i<s1.length();i++){
        char curr_char = s1[i];
        string curr_string = words[j];
        
//        cout<<i<<" "<<j<<" "<<curr_char<<" "<<curr_string<<endl;
        
        if(m.find(curr_char) == m.end()){
            if(map2.find(curr_string) != map2.end()){
                cout<<"false";
                return 0;
            }else{
                m[curr_char] = curr_string;
                map2[curr_string] = true;
            }
        }else{
            if(m[curr_char] != curr_string){
                cout<<"false";
                return 0;
            }
        }
        j++;
    }
    cout<<"true";
    return 0;
    
}
