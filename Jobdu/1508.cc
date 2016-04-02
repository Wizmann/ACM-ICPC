#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 200;

int main() {
    freopen("input.txt", "r", stdin);
    string s;
    s.reserve(SIZE);

    while (input(s)) {
        if (s.empty()) {
            puts("My God");
            continue;
        }
        size_t ptr = 0;
        char sign = '\0';

        if (s[0] == '+') {
            ptr++;
        } else if (s[0] == '-') {
            ptr++;
            sign = '-';
        }

        while (ptr < s.length() && s[ptr] == '0') {
            ptr++;
        }

        for (size_t i = ptr; i < s.size(); i++) {
            if (!isdigit(s[i])) {
                ptr = s.size();
                break;
            }
        }

        if (ptr != s.size()) {
            if (sign) {
                printf("%c", sign);
            }
            puts(s.substr(ptr).c_str());
        } else {
            puts("My God");
        }
    }
    return 0;
}


