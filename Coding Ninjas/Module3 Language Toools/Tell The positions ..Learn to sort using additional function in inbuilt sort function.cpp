#include<bits/stdc++.h>
using namespace std;

struct student{
    string name;
    int rollno;
    int total;
};

bool compare(student &s1,student &s2){
	if(s1.total != s2.total){
        return s1.total>s2.total;
    }
    else{
		return s1.rollno<s2.rollno;
    }
}
;

int main(){
	int i,n,a,b,c;
	cin>>n;
    struct student s[n];
    for(i=0;i<n;i++){
		cin>>s[i].name;
        s[i].rollno=i+1;
        cin>>a>>b>>c;
        s[i].total=(a+b+c);
    }
    sort(s,s+n,compare);
    for(i=0;i<n;i++){
		cout<<i+1<<" "<<s[i].name<<endl;
    }
}

