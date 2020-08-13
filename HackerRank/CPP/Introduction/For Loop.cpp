#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<string> strs = {
    "",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};

int main() {
    int a, b;
    while (cin >> a >> b) {
        for (int i = a; i <= b; i++) {
            if (1 <= i && i <= 9) {
                cout << strs[i] << endl;
            } else {
                if (i % 2 == 0) {
                    cout << "even" << endl;
                } else {
                    cout << "odd" << endl;
                }
            }
        }
    }
    return 0;
}
