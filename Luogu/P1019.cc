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

const int N = 22;

struct State {
    int last;
    llint visited;

    bool operator < (const State& other) const {
        if (last != other.last) {
            return last < other.last;
        }
        return visited < other.visited;
    }
};


vector<string> S;
int pre[N][N];
llint fact[N];

void init() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * 3;
    }
}

llint make_id(llint pre, int id) {
    return pre + fact[id];
}

llint get_count(llint pre, int id) {
    pre -= pre % fact[id];
    pre %= fact[id + 1];
    return pre / fact[id];
}

int main() {
    init();

    assert(make_id(0, 0) == 1);
    assert(make_id(1, 0) == 2);
    assert(make_id(1, 1) == 4);
    assert(fact[21] == 10460353203LL);

    int n;
    input(n);

    string s;
    for (int i = 0; i < n; i++) {
        input(s);
        S.push_back(s);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pre[i][j] = 0;
            int length = min(S[i].size(), S[j].size()) - 1;
            for (int k = 1; k <= length; k++) {
                bool flag = true;
                for (int p = 0; p < k; p++) {
                    if (S[i][S[i].size() - k + p] != S[j][p]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    pre[i][j] = k;
                    break;
                }
            }
            // print(i, j, pre[i][j]);
        }
    }

    input(s);
    char st = s[0];

    queue<State> q;
    map<State, int> mp;

    for (int i = 0; i < n; i++) {
        if (S[i][0] == st) {
            State state = {i, make_id(0, i)};
            q.push(state);
            mp[state] = S[i].length();
        }
    }

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int length = mp[cur];
        llint visited = cur.visited;
        for (int i = 0; i < n; i++) {
            if (get_count(visited, i) == 2) {
                continue;
            }

            if (pre[cur.last][i] == 0) {
                continue;
            }

            int nxt_last = i;
            llint nxt_visited = make_id(visited, i);
            int nxt_length = length + S[i].size() - pre[cur.last][i];

            State nxt_state = { nxt_last, nxt_visited };
            if (mp[nxt_state] < nxt_length) {
                q.push(nxt_state);
                mp[nxt_state] = nxt_length;
            }
        }
    }

    int maxi = 0;
    for (auto& p : mp) {
        maxi = max(maxi, p.second);
    }

    print(maxi);

    return 0;
}

/*
^^^TEST^^^
2
aaxxaa
aazzaa
---------
21
$$$TEST$$$$

^^^TEST^^^
5
at
touch
cheat
choose
tact
a
-----
23
$$$TEST$$$

*/
