//#include<bits/stdc++.h>
//// #include<sstream>
//using namespace std;
//
//int main(){
//    string s1,s2;
//    cin>>s1;
//    
//    fflush(stdin);
//    
//    getline(cin,s2);
////	cin.getline(s2);    
//    queue<string> words;
//    
//    // stringstream s(s2);
//    // string word;
//    // while(s >> word){
//    //     words.push_back(word);
//    // }
//    
////    for(int i=0;i<words.size();i++){
////    	cout<<words[i]<<" ";
////	}
////	cout<<endl;
//    
//    cout<<s2<<endl;
//    
//    int j = 0;
////    string s = " ";
//    cout<<s2.length();
//    for(int i=0;i<s2.length();i++){
//         
//         if(s2[i] == ' '){
//             words.push(s2.substr(j,i-j));
//             j = i+1;
//         }
//    }
//    
//     words.push(s2.substr(j));
//    
//     unordered_map<char,string> m;
//     unordered_map<string,bool> map2;
//    
//    
//     j = 0;
//    
//     for(int i=0;i<s1.length();i++){
//         char curr_char = s1[i];
//         string curr_string = words.front();
//         words.pop();
//        
//// //        cout<<i<<" "<<j<<" "<<curr_char<<" "<<curr_string<<endl;
//        
//         if(m.find(curr_char) == m.end()){
//             if(map2.find(curr_string) != map2.end()){
//                 cout<<"false";
//                 return 0;
//             }else{
//                 m[curr_char] = curr_string;
//                 map2[curr_string] = true;
//             }
//         }else{
//             if(m[curr_char] != curr_string){
//                 cout<<"false";
//                 return 0;
//             }
//         }
//         j++;
//     }
//     cout<<"true";
//    return 0;
//    
//}


#include<bits/stdc++.h>
using namespace std;

int main(){
	cout<<-12%7<<endl;
}
