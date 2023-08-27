//Extended Euclid's algorithm to find solution to an equation which says::
		
//		if ax+by = gcd(a,b) for some given values of a and b.Find the value of x and y::
//		These equations of type ax+by = gcd(a,b) = c  are known as linear diphantine equations
//		i.e the equations having integer values as root::
//Time Complexity of Euclids Algorithm is O(log2(max(a,b)))::
#include<bits/stdc++.h>
using namespace std;

struct Triplet{
	int x,y,gcd;
};

Triplet extendedEuclid(int a,int b){
	
	if(b==0){
		Triplet ans;
		ans.x = 1;
		ans.gcd = a;
		ans.y = 0;
		return ans;
	}
	
	Triplet ans;
	Triplet Smallans = extendedEuclid(b,a%b);
	ans.x = Smallans.y;
	ans.gcd = Smallans.gcd;
	ans.y = Smallans.x - (a/b)*Smallans.y;
	return ans;
}

int main(){
	int a,b;
	cin>>a>>b;
	Triplet ans = extendedEuclid(a,b);
	cout<<ans.x<<" "<<ans.y<<endl;
}
