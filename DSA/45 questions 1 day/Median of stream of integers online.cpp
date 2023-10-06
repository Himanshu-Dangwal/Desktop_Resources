//Online median of elements in a stream::

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	int n,x;
	cin>>n;
	
	priority_queue<int> max_heap;
	priority_queue<int,vector<int>,greater<int>> min_heap;
	
	//First input the first element and place it in max_heap i.w lower half::
	cin>>x;
	int median = x;
	max_heap.push(x);
	
	cout<<"Median = "<<median<<endl;
	//Make first half max_heap(smaller elements) and other half min_heap(larger elements)::
	n--;
	while(n--){
		cin>>x;
		
		if(max_heap.size() > min_heap.size()){
			if(x < median){
				int curr = max_heap.top();
				max_heap.pop();
				max_heap.push(x);
				min_heap.push(curr);
			}else{
				min_heap.push(x);
			}
			median =( max_heap.top() + min_heap.top() )/2;
		}
		else if(max_heap.size() == min_heap.size()){
			if(x < median){
				max_heap.push(x);
				median = max_heap.top();
			}else{
				min_heap.push(x);
				median = min_heap.top();
			}
		}
		else{
			if(x < median){
				max_heap.push(x);
			}else{
				int curr = min_heap.top();
				min_heap.pop();
				max_heap.push(curr);
				min_heap.push(x);
			}
			median =( max_heap.top() + min_heap.top() )/2;
		}
		cout<<"Median =  "<<median<<endl;
	}

	return 0;
}

