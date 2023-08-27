int *NextSmallerNumber(int a[],int m)	
{
	int n = m;
	stack<int> st;
	int nge[n];
	for(int i=0;i<n;i++){
		nge[i] = -1;
	}
	
	st.push(a[n-1]);
	for(int i=n-2;i>=0;i--){
		while(st.size() != 0 && st.top() >= a[i]){
			st.pop();
		}
		
		if(st.empty()){
			nge[i] = -1;
		}else{
			nge[i] = st.top();
		}
		st.push(a[i]);
	}
	
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		arr[i] = nge[i];
	}
	
	return arr;
}
	
	
