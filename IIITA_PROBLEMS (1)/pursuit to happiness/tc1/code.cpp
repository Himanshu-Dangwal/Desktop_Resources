#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    // Initialize the random number generator
    registerGen(argc, argv, 1);
    ofstream out("input.txt");
    // Generate the first test case
    int n = 100000;  // Size of the array
    out << n << endl;
    for (int i = 0; i < n; ++i) {
        int val = rnd.next(-1e9, 1e9);
        out << val << " ";
    }
    out << endl;

    // Generate the second test case with the condition
    out<<-1<<" ";
    for (int i = 1; i < n; ++i) {
        int val = rnd.next(0, i - 1); // Ensure val < i
        out << val << " ";
    }

    return 0;
}
