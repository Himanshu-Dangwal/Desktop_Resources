//Merging 3 lists and finding all those elements having occurence more than 1::
#include<bits/stdc++.h>
using namespace std;

vector<int> merge_occurence(int* a,int n){
	sort(a,a+n);
	int count;
	int j;
	int i=0;
	vector<int> result;
	while(i<n){
		count=0;
		for(j=i;j<n && (a[i]==a[j]);j++){
			count++;
		}
		if(count>=2)
			result.push_back(a[i]);
	i=j;
	}
	return result;
}

int main(){
	int n1,n2,n3;
	cin>>n1>>n2>>n3;
	int n4=n1+n2;
	int total_size[n4];
	for(int i=0;i<n4;i++){
		cin>>total_size[i];
	}
	vector<int> result = merge_occurence(total_size,n4);
	cout<<endl<<result.size()<<endl;
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<endl;
	}
	return 0;
}
