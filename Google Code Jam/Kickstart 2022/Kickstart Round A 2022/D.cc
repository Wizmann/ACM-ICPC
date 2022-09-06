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

map<llint, llint> mp;

llint get_dp_hash(const vector<int>& status) {
    assert(status.size() == 7);
    int a = status[0]; // factor 2
    int b = status[1]; // factor 3
    int c = status[2]; // factor 5
    int d = status[3]; // factor 7
    int e = status[4]; // sum
    int f = status[5]; // remaining length
    int g = status[6]; // mul == 0

    llint h = f;
    h *= 9 * 12 + 19;
    h += e;
    h *= 49;
    h += d;
    h *= 49;
    h += c;
    h *= 49;
    h += b;
    h *= 49;
    h += a;
    h *= 2;
    h += g;
    return h;
}

llint get_dp(const vector<int>& factors) {
    llint h = get_dp_hash(factors);
    if (mp.find(h) == mp.end()) {
        return -1;
    }
    return mp[h];
}

void set_dp(const vector<int>& factors, llint value) {
    llint h = get_dp_hash(factors);
    mp[h] = value;
}

void update_status(vector<int>& status, int num) {
    assert(status.size() == 7);
    status[4] += num;
    status[5] -= 1;
    switch (num) {
        case 0: {
            status[6] = 1;
        } break;
        case 1: {
            // pass
        } break;
        case 2: {
            status[0]++;
        } break;
        case 3: {
            status[1]++;
        } break;
        case 4: {
            status[0] += 2;
        } break;
        case 5: {
            status[2]++;
        } break;
        case 6: {
            status[0]++;
            status[1]++;
        } break;
        case 7: {
            status[3]++;
        } break;
        case 8: {
            status[0] += 3;
        } break;
        case 9: {
            status[1] += 2;
        } break;
        default: {
            assert(false);
            break;
        }
    }
}

bool check_ans(const vector<int>& status) {
    int a = status[0]; // factor 2
    int b = status[1]; // factor 3
    int c = status[2]; // factor 5
    int d = status[3]; // factor 7
    int e = status[4]; // sum
    int f = status[5]; // remaining length
    int g = status[6]; // mul == 0;

    assert(f == 0);

    vector<int> fs(10, 0);
    fs[2] = a;
    fs[3] = b;
    fs[5] = c;
    fs[7] = d;

    llint mul = 1;
    if (g) {
        mul = 0;
    }
    int sum = e;

    if (sum == 0) {
        return false;
    }

    for (int i = 1; i < 10; i++) {
        if (fs[i] == 0) {
            continue;
        }
        for (int j = 0; j < fs[i]; j++) {
            mul *= i;
        }
    }

    return mul % sum == 0;
}

llint dfs(int cur, int n, const vector<int>& ns, vector<int>& factors, bool flag, bool lz) {
    assert(cur == n - factors[5]);
    if (cur == n) {
        if (lz) {
            return 0;
        }
        return check_ans(factors) ? 1 : 0;
    }
    if (!flag && !lz && get_dp(factors) != -1) {
        return get_dp(factors);
    }

    llint res = 0;

    for (int i = 0; i < 10; i++) {
        vector<int> nxt = factors;
        if (flag && i > ns[cur]) {
            continue;
        } else if (flag && i == ns[cur]) {
            update_status(nxt, i);
            res += dfs(cur + 1, n, ns, nxt, true, false);
        } else {
            if (i == 0 && lz) {
                nxt[5] -= 1;
                res += dfs(cur + 1, n, ns, nxt, false, true);
            } else {
                update_status(nxt, i);
                res += dfs(cur + 1, n, ns, nxt, false, false);
            }
        }
    }

    if (!flag && !lz) {
        set_dp(factors, res);
    }
    return res;
}


llint solve(llint x) {
    string xs = std::to_string(x);
    vector<int> ns;
    const int n = xs.size();
    for (int i = 0; i < n; i++) {
        ns.push_back(xs[i] - '0');
    }

    vector<int> factors = {0, 0, 0, 0, 0, n, 0};
    return dfs(0, n, ns, factors, true, true);
}

int main() {

    for (int i = 1; i < 500; i++) {
        int u = solve(i) - solve(i - 1);
        if (u) {
            // print(i);
            assert(u == 1);
        }
    }


    int T;
    input(T);

    llint a;
    llint b;
    for (int case_ = 0; case_ < T; case_++) {
        scanf("%lld%lld", &a, &b);

        printf("Case #%d: ", case_ + 1);
        llint res = solve(b) - solve(a - 1);

        print(res);
    }

    return 0;
}

/*

^^^TEST^^^
6
1 9
91 99
451 460
501 1000
10000 1000000
12345 1234567
-----
Case #1: 9
Case #2: 0
Case #3: 5
Case #4: 176
Case #5: 530350
Case #6: 703505
$$$TEST$$$

*/
