#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 123456;
const int INF = 0x3f3f3f3f;

class Solution {
public:
    Solution(const string& s1_, const string& s2_) : \
            s1(s1_), s2(s2_), n(s1.size()), m(s2.size()), cp(m, n) {
        // pass
    }

    string solve() {
        int p = 0;
        int q = 0;
        while (p < n && q < m) {
            if (s1[p] == s2[q]) {
                cp[q] = p;
                q++;
            }
            p++;
        }

        p = n;
        q = m;
        int ptr = m - 1;
        string ans = "-";
        while (p >= 0 && q >= 0) {
            ptr = min(ptr, q - 1);
            while (ptr >= 0 && cp[ptr] >= p) {
                ptr--;
            }

            string t1;
            string t2;
            if (ptr >= 0) {
                t1 = s2.substr(0, ptr + 1) + s2.substr(q);
            }

            t2 = s2.substr(q);
            if (t1.size() >= ans.size()) {
                ans = t1;
            }
            if (t2.size() >= ans.size()) {
                ans = t2;
            }

            q--;
            p--;
            while (p >= 0 && q >= 0 && s1[p] != s2[q]) {
                p--;
            }
        }
        return ans;
    }

private:
    string s1, s2;
    int n, m;
    vector<int> cp;
};

int main() {
    assert(Solution("accac", "baacccbcccabaabbcacbbcccacbaabaaac").solve() == "aac");
    assert(Solution("gkvubrvpbhsfiuyha", "ihotmn").solve() == "ih");
    assert(Solution("abacaba", "abcdcba").solve() == "abcba");
    assert(Solution("abca", "accepted").solve() == "ac");
    assert(Solution("abcd", "accepted").solve() == "acd");
    assert(Solution("hi", "bob").solve() == "-");
 
    string s1, s2;
    input(s1 >> s2);

    puts(Solution(s1, s2).solve().c_str());

    return 0;
}
