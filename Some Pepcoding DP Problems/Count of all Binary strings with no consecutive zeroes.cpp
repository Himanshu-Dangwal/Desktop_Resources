//Count of all Binary STrings of length n with no 2 zeroes as consecutive::
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int oz = 1; //Old Zeroes::
	int oo = 1;	//Old Ones::

	for(int i=2;i<=n;i++){
		int nz = oo;      //New Zeroes::
		int no = oo + oz; //New Ones::
		
		oz = nz;
		oo = no;
	}
	cout<<oo+oz<<endl;
	return 0;
}

