#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

#define myassert(lhd, rhd) do { \
    if (lhd != rhd) { \
        cout << "L" << __LINE__ << ": assert failed: " << lhd << " != " << rhd   << endl; \
        assert(lhd == rhd); \
    } \
} while(0)

typedef long long llint;

const int INF = 0x3f3f3f3f;
const int SIZE = 111111;

llint gcd(llint a, llint b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

class Solution {
public:
    llint solve(const string& nums, int k) {
        deque<int> dq;
        llint LL = 0;
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i <= n; i++) {
            if (i < n && nums[i] == '0') {
                continue;
            } else if (i == n) {
                dq.push_back(INF);
            } else {
                dq.push_back(i);
                cnt++;
            }
            
            while (true) {
                int l = *dq.begin();
                int r = *dq.rbegin();
                if (r - l > k) {
                    dq.pop_front();
                    LL += dq.size() - 1;
                } else {
                    break;
                }
            }
        }
        return LL * 2 + cnt;
    }
};


int main() {
    int T;
    string s;
    input(T);
    while (T--) {
        int n, k;
        input(n >> k);
        input(s);
        Solution S;
        auto p = S.solve(s, k);
        auto q = 1LL * n * n;
        auto g = gcd(p, q);
        print(p / g << "/" << q / g);
    }
    return 0;
}
