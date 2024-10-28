#include <bits/stdc++.h>

using namespace std;

// Function to convert a 32-bit integer to a single-precision floating-point number
float int_to_float(int x) {
    return *(float*)&x;
}

// Function to execute a single command
void execute_command(const string& command, vector<int>& registers, const vector<vector<int>>& luts) {
    stringstream ss(command);
    string cmd;
    ss >> cmd;

    if (cmd == "C") {
        int value;
        ss >> hex >> value;
        registers.push_back(value);
    }
    else if (cmd == "N") {
        int i, j;
        ss >> i >> j;
        registers.push_back(~(registers[i] & registers[j]));
    }
    else if (cmd == "F") {
        int i, j, k;
        ss >> i >> j >> k;
        int a = registers[i], b = registers[j], c = registers[k];
        int result = a * b + c;
        registers.push_back(result);
    }
    else if (cmd == "L") {
        int i, j, b;
        ss >> i >> j >> b;
        int mask = (1 << b) - 1;
        int index = (registers[0] >> j) & mask;
        registers.push_back(luts[i][index]);
    }

}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int C0;
        cin >> hex >> C0;

        int L;
        cin >> L;
        vector<vector<int>> luts(L);
        for (int i = 0; i < L; ++i) {
            int size;
            cin >> size;
            luts[i].resize(size);
            for (int j = 0; j < size; ++j) {
                cin >> hex >> luts[i][j];
            }
        }

        int Q;
        cin >> Q;
        vector<string> commands(Q);
        for (int i = 0; i < Q; ++i) {
            cin >> commands[i];
        }

        vector<int> registers = { C0 };
        for (const string& command : commands) {
            execute_command(command, registers, luts);
        }

        cout << hex << registers.back() << endl;
    }

    return 0;
}