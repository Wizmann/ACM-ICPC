#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

char buffer[1234567];

vector<int> kmpnext(const string& s) {
    int n = s.size();
    vector<int> next(n + 1, -1);
    for (int pre = -1, suf = 0; pre < n && suf < n; /* pass */) {
        if (pre == -1 || s[pre] == s[suf]) {
            pre++;
            suf++;
            next[suf] = pre;
        } else {
            pre = next[pre];
        }
    }
    return next;
}

string solve(const vector<string>& strs) {
    string res = "";
    
    for (const auto& str: strs) {
        auto next = kmpnext(str);

        int n = res.size();
        int m = str.size();
        int p = max(0, n - m);
        int q = 0;

        for (int i = p, j = 0; i < n && j < m; /* pass */) {
            if (j == -1 || res[i] == str[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
            if (i >= n) {
                q = j;
                break;
            }
        }
        res += str.substr(q);
    }
    return res;
}

void test() {
    vector<string> s1 = {"I", "want", "ttt"};
    assert(solve(s1) == "Iwanttt");

    vector<string> s2 = {"sample", "please", "ease", "in", "out"};
    assert(solve(s2) == "sampleaseinout");

    vector<string> s3 = {"a", "a", "a"};
    assert(solve(s3) == "a");

    vector<string> s4 = {"a", "abb", "bcc"};
    assert(solve(s4) == "abbcc");
}

int main() {
    test();
    int n;
    input(n);

    vector<string> strs;

    for (int i = 0; i < n; i++) {
        scanf("%s", buffer);
        strs.emplace_back(buffer);
    }

    puts(solve(strs).c_str());

    return 0;
}
