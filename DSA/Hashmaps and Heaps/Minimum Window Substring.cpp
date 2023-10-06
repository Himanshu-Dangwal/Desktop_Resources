 //Smalllest substring of a string which contains other string::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s1,s2;
	cin>>s1>>s2;
	
	unordered_map<char,int> map2;
	
	for(int i=0;i<s2.length();i++){
		map2[s2[i]]++;
	}
	
	int i=-1;
	int j=-1;
	
	int cnt = 0;
	int rcnt = s2.length();
	
	unordered_map<char,int> map1;
	
	string ans = "";
	
	while(true){
		bool flag1 = false;
		bool flag2 = false;
		
		//acquire

	
		int n = s1.length();
		n--;

		
		while(i < n && (cnt < rcnt)){
			flag1 = true;
			i++;
			map1[s1[i]]++;

			if(map2.find(s1[i]) != map2.end()){
				if(map1[s1[i]] < map2[s1[i]]){

					cnt++;
				}
			}
			
		}
		
		//Calculating the answer and releasing values::
		
		while(j < i  && cnt == rcnt){
			
			//Calculation
			
			string pans = s1.substr(j+1,i-j);

			int x = ans.length();
			int y = pans.length();
			
			if(x == 0 || x > y){

				ans = pans;
				

			}
			
			//Release
			
			flag2 = true;
			j++;
			map1[s1[j]]--;
			

			if(map2.find(s1[j]) != map2.end()){
				
				if(map2[s1[j]] > map1[s1[j]]){
					cnt--;
				}
				
			}
		
		}
		
		
		if(flag1 == false && flag2 == false){
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}

