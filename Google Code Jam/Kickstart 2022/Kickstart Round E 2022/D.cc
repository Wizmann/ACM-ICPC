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

int dp[SIZE * 2];

void manacher(const string& str) {
    memset(dp,0,sizeof(dp));

    string s;
    int n = str.size();
    for (int i = 0; i < n; i++) {
        s += '#';
        s += str[i];
    }

    s += '#';
    n = s.size();

    int i=0,j=1,k;

    while(i<n)
    {
        while(i-j>=0 && i+j<n && s[i-j]==s[i+j]) j++;
        dp[i]=j-1;
        k=1;
        while(k<=dp[i] && dp[i]-k!=dp[i-k])
        {
            dp[i+k]=min(dp[i-k],dp[i]-k);
            k++;
        }
        i+=k;
        j=max(j-k,0);
    }
    // print(s);

    set<int> st_l, st_r;
    for (i=0; i<n; i++) {
        if (!dp[i]) {
            continue;
        }
        int left = i / 2 - dp[i] / 2;
        int right = left + dp[i] - 1;
        // print(left, right);

        if (left == 0 && right != (int)str.size() - 1) {
            // print("L", right);
            st_l.insert(right);
        }
        if (right == (int)str.size() - 1 && left != 0) {
            // print("R", left);
            st_r.insert(left);
        }
    }

    int ans = str.size() - 1;
    for (auto num : st_l) {
        if (st_r.count(num + 1)) {
            ans = min(ans, num);
        }
    }
    print(str.substr(0, ans + 1));
}

int main() {
    int T;
    input(T);

    int n;
    string s;
    for (int case_ = 0; case_ < T; case_++) {
        input(n);
        input(s);

        printf("Case #%d: ", case_ + 1);
        manacher(s);
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
