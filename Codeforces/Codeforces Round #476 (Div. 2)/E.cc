#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <numeric>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 123456;
const int ALPHA = 26;

int ord(char c) {
    return c - 'a';
}

char chr(int x) {
    return 'a' + x;
}

struct TrieNode {
    int next[ALPHA];
    bool is_end;
};

int n;
int idx;
TrieNode nodes[SIZE * 4];

void trie_init() {
    idx = 0;

    memset(nodes, -1, sizeof(nodes));

    for (int i = 0; i < SIZE * 4; i++) {
        nodes[i].is_end = false;
    }
}

void trie_insert(const string& s) {
    int cur = 0;

    for (char c: s) {
        int u = ord(c);
        if (nodes[cur].next[u] == -1) {
            nodes[cur].next[u] = ++idx;
        }
        cur = nodes[cur].next[u];
    }

    nodes[cur].is_end = true;
}

void dfs(int cur, int depth, multiset<int>& st) {
    multiset<int> curst;
    for (int i = 0; i < ALPHA; i++) {
        if (nodes[cur].next[i] != -1) {
            dfs(nodes[cur].next[i], depth + 1, curst);
        }
    }

    if (nodes[cur].is_end) {
        curst.insert(depth);
    } else if (depth != 0) {
        curst.erase(prev(curst.end()));
        curst.insert(depth);
    }

    for (auto item: curst) {
        st.insert(item);
    }

}

int main() {
    string s;
    input(n);

    trie_init();

    for (int i = 0; i < n; i++) {
        input(s);
        trie_insert(s);
    }

    multiset<int> st;
    dfs(0, 0, st);

    print(accumulate(st.begin(), st.end(), 0));

    return 0;
}
