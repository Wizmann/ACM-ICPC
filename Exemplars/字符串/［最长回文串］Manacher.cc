#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

const int SIZE = 123456;

class Manacher {
public:
    Manacher(const string& origin_) : origin(origin_) {
        int n = origin.size();
        for (int i = 0; i < n; i++) {
            s += '#';
            s += origin[i];
        }

        s += '#';
        n = s.size();

        d = vector<int>(n, 0);

        for (int i = 0, j = 1, k; i < n; /* pass */) {
            while (i - j >= 0 && i + j < n &&
                   s[i-j] == s[i+j]) {
                j++;
            }
            d[i] = j - 1;
            k = 1;
            while (k <= d[i] && d[i] - k != d[i - k]) {
                d[i + k] = min(d[i - k], d[i] - k);
                k++;
            }
            i += k;
            j = max(j - k, 0);
        }
    }

    int LongestPalindrome() const {
        int maxi = 1;
        for (auto num : d) {
            maxi = max(maxi, num);
        }
        return maxi;
    }

    int LongestOddLenPalindrome(int pivot) const {
        int idx = pivot * 2 + 1;
        int left = idx / 2 - d[idx] / 2;
        int right = left + d[idx] - 1;
        return right - left + 1;
    }

    int LongestEvenLenPalindrome(int pivot) const {
        int idx = pivot * 2 ;
        int left = idx / 2 - d[idx] / 2;
        int right = left + d[idx] - 1;
        return right - left + 1;
    }

    int LongestPalindrome(int pivot) const {
        return max(LongestOddLenPalindrome(pivot),
                   LongestEvenLenPalindrome(pivot));
    }

private:
    string origin;
    string s;
    vector<int> d;
};

string solve(const string& str) {
    Manacher m(str);
    int n = str.size();

    set<int> st_l, st_r;
    for (int i = 0; i < n; i++) {
        // odd
        {
            int len = m.LongestOddLenPalindrome(i);
            int left = i - len / 2;
            int right = left + len - 1;

            if (left == 0 && right != (int)str.size() - 1) {
                // print("L", right);
                st_l.insert(right);
            }
            if (right == (int)str.size() - 1 && left != 0) {
                // print("R", left);
                st_r.insert(left);
            }
        }

        // even
        {
            int len = m.LongestEvenLenPalindrome(i);
            int left = i - len / 2;
            int right = left + len - 1;

            if (left == 0 && right != (int)str.size() - 1) {
                // print("L", right);
                st_l.insert(right);
            }
            if (right == (int)str.size() - 1 && left != 0) {
                // print("R", left);
                st_r.insert(left);
            }
        }
    }

    int ans = str.size() - 1;
    for (auto num : st_l) {
        if (st_r.count(num + 1)) {
            ans = min(ans, num);
        }
    }
    return str.substr(0, ans + 1);
}

int main() {
    int T;
    input(T);

    int n;
    string s;
    for (int case_ = 0; case_ < T; case_++) {
        input(n);
        input(s);

        printf("Case #%d: %s\n", case_ + 1, solve(s).c_str());
    }

    return 0;
}

/*

^^^TEST^^^
3
4
abba
4
cccc
6
cdccdc
-----
Case #1: abba
Case #2: c
Case #3: cdc
$$$TEST$$$

*/
