//Given 2 points of a line.We have to calculate the distance of a point P from the line passing from the 2 given points:::

#include<bits/stdc++.h>
using namespace std;

class Point{
	public:
		double x,y;
};

double mod(double x,double y){
	double a = x*x;
	double b = y*y;
	
	double ans = sqrt(a+b);
	return ans;
}

double crossProduct(double x1,double y1,double x2,double y2){
	double p1 = x1*y2;
	double p2 = x2*y1;
	
	double p = (p1-p2);
	return fabs(p);
}

int main(){
	Point A,B,C;
	//Line passing by A and B ..And C is the point from which the perpendicular distance is to be calculated:::
	cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y;
	double x = B.x - A.x;
	double y = B.y - A.y;
	x = fabs(x);
	y = fabs(y);
	double denominator = mod(x,y);
	double x1 = B.x - A.x;
	double x2 = C.x - A.x;
	double y1 = B.y - A.y;
	double y2 = C.y - A.y;
	double numerator = crossProduct(x1,y1,x2,y2);
	
	double ans = numerator/denominator ; 
	cout<<fixed<<setprecision(4)<<ans<<endl;
}
