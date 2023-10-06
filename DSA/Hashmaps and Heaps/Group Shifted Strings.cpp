#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> getString(vector<string> &words){
    
//    cout<<"Here"<<endl;
    
    unordered_map<string,vector<string>> m;
    
    for(int i=0;i<words.size();i++){
        string curr = words[i];

        int n = curr.length();
        
//        cout<<n<<endl;
       
        
        string concatenated = "";
        string for_unit = "#";
        if(n == 1){
            m[for_unit].push_back(curr);
            continue;
        }
        
        for(int i=1,j=0;i<n;i++,j++){
            int differnce = int(curr[i] - curr[j]);
            if(differnce < 0){
            	differnce += 26;
			}
            string s = to_string(differnce);
            concatenated += s;
            concatenated += '#';
        }
        
        m[concatenated].push_back(curr);
        
    }
    
    vector<vector<string>> ans;
    
    int idx = 0;
//    cout<<"Did it reach here"<<endl;
    
//    cout<<m.size()<<endl;
    for(auto it : m){
//        cout<<"Inside"<<endl;
        
//        cout<<endl;
//        cout<<it.first<<endl;
//        cout<<it.second.size()<<endl;
		vector<string> temp;
        for(int i=0;i<it.second.size();i++){
//        	cout<<it.second[i]<<endl;
        	string ch = it.second[i];
//        	cout<<"Is there?"<<endl;
//        	cout<<idx<<" ";
//          ans[idx].push_back(ch); 
//			ans[0].push_back(ch);
//			cout<<i<<endl;   
			temp.push_back(ch);
        }
        ans.push_back(temp);
//        cout<<"And here"<<endl;
        idx++;
        
    }
//    cout<<ans.size()<<endl;
    
//    cout<<ans[0].size()<<endl;
//    cout<<ans[1].size()<<endl;
//    cout<<ans[2].size()<<endl;
//    cout<<"Returning"<<endl;
    return ans;
    
}


bool compare(vector<string> a,vector<string> b){
    if(a.size() != b.size()){
        return a.size() > b.size();
    }
    
    string first = a[0];
    string second = b[0];
    
    // return first[0] < second[0];
    
    int size = min(first.length(),second.length());
    
    for(int i=0;i<size;i++){
        if(first[i] != second[i]){
            return first[i] < second[i];
        }
    }
    
    return first.length() < second.length();
    
}

int main(){
    
    int n;
    cin>>n;
    
    vector<string> words;
    
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        
        words.push_back(s);
    }
    
    vector<vector<string>> ans = getString(words);
    
//    cout<<"Here"<<endl;
    
    //Ans currrently consists of strings having same ASCII difference of consecutive characters
    
    for(int i=0;i<ans.size();i++){
        sort(ans[i].begin(),ans[i].end());
    }
    
    sort(ans.begin(),ans.end(),compare);
    
//    for(int i=0;i<ans.size();i++){
//        for(int j=0;j<ans[i].size();i++){
//            cout<<ans[i][j]<<" ";
//        }
//        cout<<endl;

	
//    }
      for(auto x : ans){
      	vector<string> curr = x;
//      	cout<<x.size();
      	
      	for(int i=0;i<x.size();i++){
      		cout<<x[i]<<" ";
		}
		cout<<endl;
      	
	  }
}
