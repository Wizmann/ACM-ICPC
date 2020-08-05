#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint MOD = 0xdeadbeefdead;
const int PRIME = 29;

const int SIZE = 1'111'111;
char buffer[SIZE];

const string NO_ANSWER = "Just a legend";

vector<int> kmp_next(const string& s) {
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

string solve(const string& s) {
    int n = s.size();
    set<int> ps;

    {
        llint ph = 0;
        llint sh = 0;
        llint base = 1;
        for (int i = 0; i < n; i++) {
            ph = (ph * PRIME % MOD + s[i] - 'a' + 1) % MOD;
            sh = (sh + 1LL * (s[n - i - 1] - 'a' + 1) * base) % MOD;
            base = base * PRIME % MOD;
            // print(ph << ' ' << sh);

            if (ph == sh) {
                ps.insert(i + 1);
            }
        }
    }

    if (ps.size() == 0) {
        return NO_ANSWER;
    }
    
    vector<int> next = kmp_next(s);

    int maxi = -1;
    for (int i = 1; i < n; i++) {
        int p = next[i];
        if (p == 0) {
            continue;
        }
        if (ps.count(p) == 0) {
            continue;
        }
        // print(s.substr(0, maxi));
        maxi = max(maxi, p);
    }

    if (maxi == -1) {
        return NO_ANSWER;
    } else {
        return s.substr(0, maxi);
    }
}

void test() {
    assert(solve("aaa") == "a");
    assert(solve("aaba") == "a");
    assert(solve("aabx") == NO_ANSWER);
    assert(solve("fixprefixsuffix") == "fix");
    assert(solve("abcdabc") == NO_ANSWER);
}

int main() {
    // test();

    scanf("%s", buffer);
    string s(buffer);
    puts(solve(s).c_str());

    return 0;
}
