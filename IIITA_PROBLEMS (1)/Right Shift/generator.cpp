#include "testlib.h"
#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
using namespace std;
#define nl '\n'
#include <ctime>
int random(){
    return 5;
    int x=rnd.next(0ll,(int)1e9);
    return 1+(x)%((int)1e9);
}
signed main(int64_t argc, char *argv[])
{
    registerGen(argc, argv, 1);
    string x;
    cin >> x;
    ofstream out("TestCase" + x + "/input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    out << 100000 << nl;
     
    
    vector<int> z;
     for (int i = 0; i < 100000; i++)
    {
         
        int f=random();
        z.push_back(f);
    }
     //sort(z.rbegin(),z.rend());
    for(int i=0;i<z.size();i++) out<<z[i]<<nl;
    out.close();
}