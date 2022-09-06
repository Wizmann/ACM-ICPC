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

const int ALPHA = 2;

class Trie {
private:
    struct TrieNode {
        TrieNode() {
            is_end = false;
            next = vector<int>(ALPHA, -1);
        }
        bool is_end;
        vector<int> next;
    };
public:
    void init() {
        do_append();
    }
    void add(const string& str) {
        do_add(str, 0, 0);
    }
    bool search(const string& str) {
        return do_search(str, 0, 0);
    }
private:
    void do_append() {
        _nodes.push_back(TrieNode());
        idx = _nodes.size() - 1;
    }
    void do_add(const string& str, int ptr, int pos) {
        if ((int)str.size() == ptr) {
            _nodes[pos].is_end = true;
            return;
        }
        int cur = str[ptr] - '0';
        if (_nodes[pos].next[cur] == -1) {
            do_append();
            _nodes[pos].next[cur] = idx;
        }
        pos = _nodes[pos].next[cur];
        do_add(str, ptr + 1, pos);
    }
    bool do_search(const string& str, int ptr, int pos) {
        if ((int)str.size() == ptr) {
            return _nodes[pos].is_end;
        }
        char cur_c = str[ptr];

        int cur = cur_c - '0';
        int next = _nodes[pos].next[cur];
        
        if (next == -1) {
            return false;
        }
        return do_search(str, ptr + 1, next);
    }
private:
    int idx;
    vector<TrieNode> _nodes;
};

int n, m, p;
vector<int> req;
char buffer[1234];

struct Node {
    std::string s;
    int val;

    bool operator < (const Node& other) const {
        return val < other.val;
    }
};

int main() {
    int T;
    input(T);
    
    for (int case_ = 0; case_ < T; case_++) {
        Trie trie;

        input(n, m, p);
        req = vector<int>(p, 0);

        for (int i = 0; i < n; i++) {
            scanf("%s", buffer);
            for (int j = 0; j < p; j++) {
                if (buffer[j] == '1') {
                    req[j]++;
                }
            }
        }

        trie.init();

        for (int i = 0; i < m; i++) {
            scanf("%s", buffer);
            string s(buffer);
            trie.add(s);
        }

        priority_queue<Node, vector<Node>, less<Node> > pq[2];

        pq[1].push({"", 0});

        for (int i = 0; i < p; i++) {
            int cur = i % 2;
            int pre = cur ^ 1;

            pq[cur] = {};

            while (!pq[pre].empty()) {
                Node u = pq[pre].top();
                pq[pre].pop();

                int delta1 = n - req[i];
                int delta0 = req[i];

                Node u1 = { u.s + "1", u.val + delta1 };
                Node u0 = { u.s + "0", u.val + delta0 };

                pq[cur].push(u0);
                pq[cur].push(u1);

                while ((int)pq[cur].size() > m + 3) {
                    pq[cur].pop();
                }
            }
        }

        int mini = INF;
        auto& last = pq[(p - 1) % 2];
        while (!last.empty()) {
            Node u = last.top();
            last.pop();

            const string& s = u.s;
            if (trie.search(s)) {
                continue;
            }
            mini = min(mini, u.val);
        }

        printf("Case #%d: %d\n", case_ + 1, mini);
    }

    return 0;
}

/*

^^^TEST^^^
3
3 1 4
1100
1010
0000
1000
3 1 4
1100
1010
0000
1000
2 4 4
1111
1111
1111
0111
1011
1101
-----
Case #1: 4
Case #2: 4
Case #3: 2
$$$TEST$$$

^^^^TEST^^^
3
1 1 1
1
1
1 1 1
1
0
1 0 1
1
-------
Case #1: 1
Case #2: 0
Case #3: 0
$$$TEST$$$

*/
