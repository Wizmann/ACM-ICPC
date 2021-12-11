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

int n;
vector<int> Ts;
vector<int> As;

llint count1(const vector<int>& ns) {
    map<int, int> mp;
    for (auto num : ns) {
        mp[num]++;
    }

    int pre = 0;
    llint tot = 0;
    for (auto& p : mp) {
        int rem = n - pre - p.second;
        tot += 1LL * p.second * rem;
        pre += p.second;
    }
    return tot;
}

struct Event {
    int l;
    int r;
};

int lowbit(int x) { return x & (-x); }

template <typename T>
class BIT
{
public:
    BIT() {}
    BIT(int n_) : n(n_), nums(n + 1) {}

    void add(int x, T val) {
        while(x < n) {
            nums[x] += val;
            x += lowbit(x);
        }
    }

    T sum(int x) {
        T res = 0;
        while(x > 0) {
            res += nums[x];
            x -= lowbit(x);
        }
        return res;
    }

    T sum(int a, int b) {
        return sum(b) - sum(a - 1);
    }
private:
    int n;
    vector<T> nums;
};

llint count2(const vector<int>& ns1, const vector<int>& ns2) {
    vector<Event> events;
    events.reserve(n * 2);

    int m = 1;
    map<int, int> mp;
    for (auto num : ns1) {
        mp[num] = -1;
    }
    for (auto num : ns2) {
        mp[num] = -1;
    }
    for (auto& p : mp) {
        p.second = m++;
    }

    for (int i = 0; i < n; i++) {
        int a = mp[ns1[i]];
        int b = mp[ns2[i]];

        events.push_back({a, b});
    }

    BIT<llint> bit(m + 1);

    sort(events.begin(), events.end(),
            [](const Event& e1, const Event& e2) {
                if (e1.l != e2.l) {
                    return e1.l < e2.l;
                } else {
                    return e1.r < e2.r;
                }
            });

    llint tot = 0;
    for (int i = 0; i < events.size(); i++) {
        auto& e = events[i];
        int l = e.l;
        int r = e.r;
        tot += bit.sum(r + 1, m);
        bit.add(r, 1);
    }
    return tot;
}

int main() {
    input(n);

    Ts.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &Ts[i]);
    }

    As.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &As[i]);
    }

    llint conflict = 0;
    conflict += count1(Ts);
    conflict += count1(As);

    conflict -= count2(Ts, As);

    print(1LL * n * n - conflict);

    return 0;
}

/*

^^^TEST^^^
3
50 100 150
1 3 2
-----
4
$$$TEST$$$

^^^TEST^^^
3
123456789 123456 123
987 987654 987654321
-----
6
$$$TEST$$$


^^^TEST^^^
10
3 1 4 1 5 9 2 6 5 3
2 7 1 8 2 8 1 8 2 8
-----
37
$$$TEST$$$


*/
