#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <numeric>
#include <set>
#include <map>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int INF = 0x3f3f3f3f;

map<char, char> gm;
map<char, char> lm;

string pop_back(const string& s) {
    int l = s.size();
    return s.substr(0, l - 1);
}

string solve(string num) {
    char last = *num.rbegin();
    num = pop_back(num);
    num = pop_back(num);
    num.push_back(last);

    int n = num.size();
    for (int i = n - 1; i >= 0; i--) {
        int ptr = -1;
        char mini = '~';
        bool flip = false;

        for (int j = i; j < n; j++) {
            char cur = num[j];
            char fur = gm.count(cur) == 0? cur: gm[cur];

            if (cur > num[i] && cur < mini) {
                mini = cur;
                ptr = j;
                flip = false;
            }

            if (fur > num[i] && fur < mini) {
                mini = fur;
                ptr = j;
                flip = true;
            }
        }

        if (ptr == -1) {
            continue;
        }

        swap(num[i], num[ptr]);
        if (flip) {
            num[i] = gm[num[i]];
        }

        for (int j = i + 1; j < n; j++) {
            num[j] = lm.count(num[j]) == 0? num[j]: lm[num[j]];
        }

        sort(num.begin() + i + 1, num.end());

        char last = *num.rbegin();
        num = pop_back(num);
        num = num + "." + last;

        return num;
    }
    return "";
}


int main() {
    freopen("input.txt", "r", stdin);
    string num;

    gm['2'] = '5';
    gm['6'] = '9';
    gm['5'] = '2';
    gm['9'] = '6';

    lm['5'] = '2';
    lm['9'] = '6';

    assert(solve("230.0") == "300.2");
    assert(solve("19.9") == "61.6");
    assert(solve("1234.5") == "1235.4");

    while (input(num) && num != ".") {
        string res = solve(num);

        if (res.empty()) {
            puts("The price cannot be raised.");
        } else {
            print(res);
        }
    }

    return 0;
}
