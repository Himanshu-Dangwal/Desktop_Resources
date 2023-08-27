//Area of Polu=ygon having n sides::::
//Very Important must write under 5 minutes atmost::

#include<bits/stdc++.h>
using namespace std;

class Points{
	public:
		double x,y;
};

class Polygon{
	public:
		Points *points;
		Polygon(int nPoints){
			points = new Points[nPoints];
		}
};

double area(Polygon p,int n){
	double fans = 0;
	for(int i=1;i<n-1;i++){
		
		double x1 = p.points[i].x - p.points[0].x;
		double y1 = p.points[i].y - p.points[0].y;
		double x2 = p.points[i+1].x - p.points[0].x;
		double y2 = p.points[i+1].y - p.points[0].y;
		
		double ans = x1*y2 - x2*y1;
		fans = fans + fabs(ans);
	}
	return fabs(fans/2);
}

int main(){
	int n;
	cin>>n;
	Polygon p(n);
	for(int i=0;i<n;i++){
		cin>>p.points[i].x>>p.points[i].y;
	}
	
//	
//	for(int i=0;i<n;i++){
//		cout<<p.points[i].x<<p.points[i].y;
//	}
	
	double ans = area(p,n);
	cout<<fixed<<setprecision(4)<<ans<<endl;
	return 0;
}
