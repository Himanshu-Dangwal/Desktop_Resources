//Bisection Method to Solve polynomila nad trancedant equations::

/*
Problem Statement::
	We are given a function as an equation with 2 values x1 and x2 such tha (f(x1)*f(x2)<0):
		Using this condtion each time the loop follows we have to find x i.e the root of the eqaution after n number of iterations or havibg certain
		number of decimal places::
*/

/*			
Algorithm::			
	set iteration=0; 
	Step 1::find mid of x1 and x2 and find the value of function f(x)::
		that value of function at f(x) will be the root of the equation after 1 iteration::
		Now check if(f(x1)*f(x)<0){
						set x2=x:
							iterations++;
							and go to step 1 if iterations<n
					}else{
						set x2=x;
							iterations++;
							and goto step 1 if iterations<n;
					}	
*/					
					
#include<bits/stdc++.h>
using namespace std;

double fun(double x){
	return (x*x*x - 3*x*x + x - 3);
}

double bisection(double x1,double x2,int n){
	int count =0;
	while(count<n){
	
		double x=(x1+x2)/2;
		if(fun(x)==0){
		{
			cout<<fun(x);
			count++;
		}	
		}else{
			if(fun(x1)*fun(x)<0){
				x2=x;
			}else{
				x1=x;
			}
			count++;
		}
	}
}

int main(){
	cout<<"Enter the 2 values of x1 and x2 respectively::"<<endl;
	double x1,x2;
	int n;
	cin>>x1>>x2;
	cout<<"Enter the number of itgearation required";
	double result = bisection(x1,x2,n);
	cout<<"Result after "<<n<<" iteration is "<<result;
	return 0;
}			
