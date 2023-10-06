#include<bits/stdc++.h>
using namespace std;

bool compare(unordered_map<char,int> &map1, unordered_map<char,int> &map2){
	
//	cout<<"called ";
	
    if(map1.size() != map2.size()){
    	
//    	cout<<map1.size()<<" "<<map2.size()<<" ";
    	
//    	cout<<"returning false from here"<<endl;
        return false;
	}
    
        
    for(auto it : map1){
        char ch = it.first;
//        cout<<ch<<" ";
        
        if(map2.find(ch) == map2.end()){
//        	cout<<"False from here"<<endl;
        	return false;
		}
        
        if(map1[ch] != map2[ch]){
//            cout<<"returning false"<<endl;
            return false;
        }
    }
//    cout<<"Returning true"<<endl;
    return true;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    
    int n1 = s1.length();
    int n2 = s2.length();
    
    unordered_map<char,int> map1;
    unordered_map<char,int> map2;
    
    for(int i=0;i<n2;i++){
        map1[s1[i]]++;
        map2[s2[i]]++;
    }
    
    int j = n2;
   	vector<int> ans;
	int count = 0; 
    for(int i=n2;i<n1;i++){
    	
//    	cout<<endl;
//    	cout<<map1.size()<<" "<<map2.size();
//    	cout<<endl;
    	
    	
        if(compare(map1,map2)){
//          cout<<i<<" Here";
			count++;
			ans.push_back(i-n2);
//          cout<<i-n2<<" ";
        }
        map1[s1[i-j]]--;
        map1[s1[i]]++;
        
        if(map1[s1[i-j]] == 0){
//        	cout<<" "<<s1[i-j]<<" It gets removed";
            map1.erase(s1[i-j]);
        }
    }
    
    if(compare(map1,map2)){
    	count++;
//      cout<<n2-n1;
		ans.push_back(n1-n2);
    }
    
    cout<<count<<endl;
    for(int i=0;i<ans.size();i++){
    	cout<<ans[i]<<" ";
	}
    
    
    return 0;
}
