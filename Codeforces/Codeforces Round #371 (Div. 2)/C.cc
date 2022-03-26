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

const int SIZE = 30;
const int DIGITS = 2;

class Trie {
public:
    Trie() {
        nodes.emplace_back();
    }

    void insert(const string& s, int delta) {
        do_insert(0, s, 0, delta);
    }

    int query(const string& s) {
        return do_query(0, s, 0);
    }

private:
    void do_insert(int cur, const string& s, int p, int delta) {
        if ((int)s.size() == p) {
            nodes[cur].count += delta;
            return;
        }
        int c = s[p] - 'a';

        if (nodes[cur].next[c] == -1) {
            nodes[cur].next[c] = nodes.size();
            nodes.emplace_back();
        }
        int nxt = nodes[cur].next[c];
        do_insert(nxt, s, p + 1, delta);
    }

    int do_query(int cur, const string& s, int p) {
        assert(cur != -1);
        if ((int)s.size() == p) {
            return nodes[cur].count;
        }
        int c = s[p] - 'a';
        int nxt = nodes[cur].next[c];
        if (nxt == -1) {
            return 0;
        }
        return do_query(nxt, s, p + 1);
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
    int q;
    input(q);

    char cmd[5];
    char num[100];
    Trie trie;
    while (q--) {
        scanf("%s%s", cmd, num);

        string query(SIZE, 'a');

        if (cmd[0] == '+' || cmd[0] == '-') {
            int m = strlen(num);
            int p = SIZE - 1;

            for (int i = m - 1; i >= 0; i--) {
                query[p] = (num[i] - '0') % 2 == 0? 'a': 'b';
                p--;
            }
            // print(num, query, cmd[0]);

            trie.insert(query, cmd[0] == '+'? 1: -1);
        } else {
            assert(cmd[0] == '?');
            int m = strlen(num);
            int p = SIZE - 1;

            for (int i = m - 1; i >= 0; i--) {
                query[p] = num[i] == '0'? 'a': 'b';
                p--;
            }

            int res = trie.query(query);
            // print(num, query, cmd[0]);

            printf("%d\n", res);
        }
    }

    return 0;
}

/*

^^^TEST^^^
12
+ 1
+ 241
? 1
+ 361
- 241
? 0101
+ 101
? 101
- 101
? 101
+ 4000
? 0
-----
2
1
2
1
1
$$$TEST$$$

^^^^TEST^^^
4
+ 200
+ 200
- 200
? 0
-------
1
$$$TEST$$$


*/
