////Maximum SUm Non Adjacent Elements
//
//#include<bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int n;
//	cin>>n;
//	int arr[n];
//	for(int i=0;i<n;i++){
//		cin>>arr[i];
//	}
//	int max_sum[n];
//	max_sum[0] = arr[0];
//	max_sum[1] = max(arr[0],arr[1]);
//	for(int i=2;i<n;i++){
//		max_sum[i] = max(max_sum[i-1],arr[i] + max_sum[i-2]);
//	}
//	cout<<max_sum[n-1];
//}


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;cin>>arr[i++]);
    
    int inc = arr[0];
    int exc = 0;
    
    for(int i=1;i<n;i++){
        int ninc = exc + arr[i];
        int nexc = max(inc,exc);
        
        inc = ninc;
        exc = nexc;
    }
    
    cout<<max(inc,exc);
}
