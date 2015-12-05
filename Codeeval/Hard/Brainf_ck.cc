#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

class Solution {
public:
    void run_brainfuck(const string& program) {
        int n = program.size();
        map<int, char> cells;
        int ptr = 0;
        stack<int> st;

        for (int i = 0; i < n; /* pass */) {
            char cmd = program[i];
            switch (cmd) {
                case '>':
                    ptr++;
                    i++;
                    break;

                case '<':
                    ptr--;
                    i++;
                    break;

                case '+':
                    cells[ptr]++;
                    i++;
                    break;

                case '-':
                    cells[ptr]--;
                    i++;
                    break;

                case '.':
                    printf("%c", cells[ptr]);
                    i++;
                    break;

                case '[': {
                    if (cells[ptr] != 0) {
                        st.push(i);
                        i++;
                    } else {
                        int cur = i;
                        while (true) {
                            if (program[i] == '[') {
                                st.push(i);
                            }
                            if (program[i] == ']') {
                                int p = st.top();
                                st.pop();
                                if (p == cur) {
                                    break;
                                }
                            }
                            i++;
                        }
                        i++;
                    }
                } break;

                case ']': {
                    if (cells[ptr] != 0) {
                        i = st.top();
                        st.pop();
                    } else {
                        st.pop();
                        i++;
                    }
                } break;

                default:
                    print("fuck me");
                    break;
            }
        }
        puts("");
    }
};
int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        Solution S;
        S.run_brainfuck(line);
    }
    return 0;
}
