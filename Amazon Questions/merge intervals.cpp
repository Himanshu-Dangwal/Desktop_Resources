{
	vector<vector<int>> intervals;
	for(int i=0;i<n;i++){
		int x = barrier[i][0];
		int y = barrier[i][1];
		int d = barrier[i][2];
		vector<int> temp;
		temp.push_back(x);
		temp.push_back(x+d);
		intervals.push_back(temp);
	}
	sort(intervals.begin(),intervals.end());
    vector<int> temp = intervals[0];
        
    for(auto it : intervals){
        if(it[0] <= temp[1]){
            temp[1] = max(it[1],temp[1]);
        }else{
            mergedIntervals.push_back(temp);
            temp = it;
        }
    }
    int ans = 0;
    mergedIntervals.push_back(temp);
	for(auto x : mergedIntervals){
		ans += x[1]-x[0]+1;
	}
	
	return ans;
}
