#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int ALPHA = 26;
const int SIZE = 123456;

class Trie {
public:
    Trie(): _idx(0) {
        _trie.reserve(SIZE);
        _trie.push_back(vector<int>(ALPHA, -1));
    }

    void add(const string& str) {
        int cur = 0;
        for (char c: str) {
            auto& node = _trie[cur];
            int p = c - 'a';
            if (node[p] == -1) {
                _trie.push_back(vector<int>(ALPHA, -1));
                node[p] = ++_idx;
            }
            cur = node[p];
        }
    }

    int traverse(int cur, char c) {
        assert(cur < (int)_trie.size());
        return _trie[cur][c - 'a'];
    }
private:
    int _idx;
    vector<vector<int> > _trie;
};

int n, k;
Trie trie;

bool dfs0(int cur) {
    bool res = false;
    for (int i = 0; i < ALPHA; i++) {
        char c = 'a' + i;
        int next = trie.traverse(cur, c);
        if (next == -1) {
            continue;
        }
        res |= !dfs0(next);
    }
    return res;
}

bool dfs1(int cur) {
    bool res = false;
    int cnt = 0;
    for (int i = 0; i < ALPHA; i++) {
        char c = 'a' + i;
        int next = trie.traverse(cur, c);
        if (next == -1) {
            continue;
        }
        cnt++;
        res |= !dfs1(next);
    }
    return res | (cnt == 0);
}


int main() {
    freopen("input.txt", "r", stdin);
    string s;
    input(n >> k);
    for (int i = 0; i < n; i++) {
        input(s);
        trie.add(s);
    }

    bool mustWin = dfs0(0);
    bool mustLose = dfs1(0);

    if (!mustWin) {
        puts("Second");
    } else if (mustLose) {
        puts("First");
    } else {
        puts(k % 2 == 0? "Second": "First");
    }

    return 0;
}
