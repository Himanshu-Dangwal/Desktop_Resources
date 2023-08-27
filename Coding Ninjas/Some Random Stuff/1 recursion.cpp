#include <iostream>
using namespace std;

void print(int n){
    if(n < 0){
        return;
    }
    if(n == 0){
        cout << n <<endl;
        return;
    }
    cout<<n;
    print(n --);
    cout << n <<endl;
}

int main() {
    int num = 3;
    print(num);
}
