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

const int SIZE = 12345;
const int DIGITS = 10;

class Trie {
public:
    Trie() {
        nodes.emplace_back();
    }

    bool insert(const string& s, int delta) {
        return do_insert(0, s, 0, delta) > 0;
    }
private:
    int do_insert(int cur, const string& s, int p, int delta) {
        if ((int)s.size() == p) {
            nodes[cur].count += delta;
            return 0;
        }
        int c = s[p] - '0';

        int ret = 0;
        if (nodes[cur].count) {
            ret = -INF;
        }
        if (nodes[cur].next[c] == -1) {
            nodes[cur].next[c] = nodes.size();
            nodes.emplace_back();
            ret++;
        }
        int nxt = nodes[cur].next[c];
        int ret2 = do_insert(nxt, s, p + 1, delta);
        if (ret2 < 0) {
            ret = -INF;
        } else {
            ret += ret2;
        }
        return ret;
    }

private:
    struct TrieNode {
        TrieNode() : count(0), next(DIGITS, -1) {
            // pass
        }

        int count;
        vector<int> next;
    };

    int idx = 0;
    deque<TrieNode> nodes;
};

int main() {
    int T;
    input(T);

    while (T--) {
        int n;
        input(n);

        Trie trie;
        string s;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            input(s);

            if (!trie.insert(s, 1)) {
                flag = false;
            }
        }
        if (flag) {
            puts("YES");
        } else {
            puts("NO");
        }
    }

    return 0;
}

/*

^^^TEST^^^
3
3
911
97625999
91125426
5
113
12340
123440
12345
98346
2
111111
11
-----
NO
YES
NO
$$$TEST$$$

*/
