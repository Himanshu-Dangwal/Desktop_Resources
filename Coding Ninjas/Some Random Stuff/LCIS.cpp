#include<bits/stdc++.h>
using namespace std;
int less(int *arr,int a,int b,int n){
    for(int i=0;i<n;i++){
		if(arr[i]==a){
            return a;
        }
        else if(arr[i]==b){
            return b;
        }
    }
}

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    // a[]=3 7 2 1 9 8 41
    vector<int> v;
    unordered_map<int,int> m;
    int start,count,best_count=0,least_value,highest_value;
    int end;
    for(int i=0;i<n;i++){
        m[arr[i]]=1;
    }
    for(int i=0;i<n;i++){
        count=0;
        int val,h;
        start=i;
        end=i;
        int k=arr[i];
        int u=arr[i];
        int p=1;
        if(m[arr[i]]==1){
       		 while(m.find(arr[end]+p)!=m.end()){
            	m[arr[end]+p]=0;
            	u=arr[end]+p;
            	p++;
            	count++;
        	 }
        	 p=1;
        	 while(m.find(arr[start]-p)!=m.end()){
            	m[arr[start]-p]=0;
            	k=arr[start]-p;
            	p++;
            	count++;
        	 }
   	    	 if(best_count<count){
        		best_count=count;
            	least_value=k;
            	m=least_value;
                highest_value=u;
                h=highest_value;
    		 }
            if(best_count==count){
                best_count=count;
                least_value=less(arr,m,k,n);
                if(least_value==m)
                    	highest_value=h;
                else
                    	highest_value=u;
            }
        }
       m[arr[i]]=0; 
    }
    v.push_back(least_value);
    v.push_back(highest_value);
    return v;
}
int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    cout << ans[0];
    if (ans.size() > 1) {
        cout << " " << ans[ans.size() - 1];
    }

    delete[] arr;
}
