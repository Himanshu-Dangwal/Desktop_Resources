//Euler's Totient Function::
//#include<bits/stdc++.h>
//#define MAX 1000000
//using namespace std;
//
//int EulersTotient(int n){
//	int sieve[n+1];
//	for(int i=0;i<=n;i++){
//		sieve[i] = i;
//	}
//	for(int i=2;i<=n;i++){
//		if(sieve[i] == i){
//			sieve[i] = i-1;
//			for(int j=i*2;j<=n;j+=i){
//				sieve[j] = (sieve[j]*(i-1))/i;
//			}
//		}
//	}	
//	return sieve[n];
//}
//
//int main(){
//
//	int t;
//	cin>>t;
//	while(t--){
//		int n;
//		cin>>n;
//		cout<<EulersTotient(n)<<endl;
//	}
//}


int EulersTotient(int n){
    int result = n;
    for(int i=2;i*i<=n;i++){
        if(n%i == 0){
            while(n%i == 0){
                n = n/i;
            }
            result = result - result/i;
        }
    }
    if(n > 1){
        result = result - result/n;
    }
    return result;
}

int main(){

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<EulersTotient(n)<<endl;
	}
}
