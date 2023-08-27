#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	int w1,w2,x1,x2,M;
	while(t--){
	    cin>>w1>>w2>>x1>>x2>>M;
	    int min = x1*M;
	    int max = x2*M;
	    if((w2-w1 <=max) && (w2-w1 <=min)){
	        cout<<"1"<<endl;
	    }else{
	        cout<<"0"<<endl;
	    }
	}
	return 0;
}

