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

typedef long long llint;

class Solution {
public:
    Solution(const string& stair_): stair(stair_), n(stair_.size())
    {
        for (int i = 0; i < n; i++) {
            char c = stair[i];
            if (c == 'U') {
                upstair.push_back(i);
            } else {
                downstair.push_back(i);
            }
        }

        downstair_sum.resize(downstair.size(), 0);
        for (ssize_t i = downstair.size() - 1; i >= 0; i--) {
            if (i == downstair.size() - 1) {
                downstair_sum[i] = n - downstair[i] - 1;
                continue;
            }
            downstair_sum[i] += n - downstair[i] - 1;
            downstair_sum[i] += downstair_sum[i + 1];
        }

        upstair_sum.resize(upstair.size(), 0);
        for (ssize_t i = 0; i < upstair.size(); i++) {
            if (i == 0) {
                upstair_sum[i] = upstair[i];
                continue;
            }
            upstair_sum[i] += upstair[i]; 
            upstair_sum[i] += upstair_sum[i - 1];
        }
    }

    pair<int, int> do_count(int pos) {
        int us = (lower_bound(upstair.begin(), upstair.end(), pos) - upstair.begin());
        int ds = downstair.end() - lower_bound(downstair.begin(), downstair.end(), pos) - (stair[pos] == 'D');
        return {us, ds};
    }

    llint solve(int pos) {
        char c = stair[pos];
        auto ps = do_count(pos);

        llint us = ps.first;
        llint ds = ps.second;

        int cnt = min(us, ds);
        llint uc = cnt + (c == 'D' && us > ds);
        llint dc = cnt + (c == 'U' && us < ds);

        last = 0;
        if (us > ds || (us == ds && c == 'U')) {
            last = n - pos - 1;
        } else {
            last = pos;
        }

        a = uc == 0? 0: pos * uc - (upstair_sum[us - 1] - (us == uc? 0: upstair_sum[us - 1 - uc]));
        b = dc == 0? 0: (n - pos - 1) * dc - (downstair_sum[downstair.size() - ds] - (ds == dc? 0: downstair_sum[downstair.size() - ds + dc]));
        // print(a << ' ' << b);
        return a * 2 + b * 2 + last + 1;
    }

public:
    llint a, b, last;

private:
    string stair;
    int n;

    vector<llint> upstair;
    vector<llint> downstair;
    vector<llint> upstair_sum;
    vector<llint> downstair_sum;
};

void test() {
    Solution S1("UD");
    assert(S1.do_count(0).first == 0);
    assert(S1.do_count(0).second == 1);
    assert(S1.do_count(1).first == 1);
    assert(S1.do_count(1).second == 0);
    
    S1.solve(0);
    assert(S1.last == 0);
    assert(S1.a == 0);
    assert(S1.b == 1);
    
    S1.solve(1);
    assert(S1.last == 0);
    assert(S1.a == 1);
    assert(S1.b == 0);
    
    Solution S2("UDDU");
    assert(S2.do_count(0).first == 0);
    assert(S2.do_count(0).second == 2);
    
    Solution S3("UDDU");
    assert(S3.do_count(1).first == 1);
    assert(S3.do_count(1).second == 1);
    
    Solution S4("UDDU");
    assert(S4.do_count(0).first == 0);
    assert(S4.do_count(0).second == 2);
    
    Solution S5("UUD");
    assert(S5.solve(0) == 5);
    assert(S5.solve(1) == 6);
    assert(S5.solve(2) == 3);
    
    Solution S6("UUDUDUUDDU");
    assert(S6.solve(0) == 5);
    assert(S6.solve(1) == 12);
}

int main() {    
    test();
    int n;
    string stair;

    input(n);
    input(stair);

    Solution S(stair);

    for (int i = 0; i < n; i++) {
        cout << S.solve(i) << " ";
    }
    puts("");

    return 0;
}
