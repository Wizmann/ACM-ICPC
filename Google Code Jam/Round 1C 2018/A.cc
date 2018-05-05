#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int ALPHA = 30;
const int SIZE = 123456;

int ord(char c) {
    return c - 'A';
}

char chr(int x) {
    return 'A' + x;
}

struct TrieNode {
    bool isEnd;
    int next[ALPHA];
};

class Trie {
public:
    Trie(int l) {
        length = l;
        nodes = vector<TrieNode>(SIZE);

        for (int i = 0; i < SIZE; i++) {
            nodes[i].isEnd = false;
            memset(nodes[i].next, -1, sizeof(nodes[i].next));
        }

        charsets.resize(l);
        idx = 0;
    }

    void insert(const string& s) {
        int ptr = 0;
        const int n = s.size();
        for (int i = 0; i < n; i++) {
            charsets[i].insert(s[i]);
            int c = ord(s[i]);
            if (nodes[ptr].next[c] == -1) {
                nodes[ptr].next[c] = ++idx;
            }
            ptr = nodes[ptr].next[c];
        }
        nodes[ptr].isEnd = true;
    }

    bool traverse(string& res, int cur, int n, int ptr) {
        if (res.size() == length) {
            return false;
        }
        for (int j = 0; j < ALPHA; j++) {
            if (charsets[cur].count(chr(j)) == 0) {
                continue;
            }
            if (nodes[ptr].next[j] == -1) {
                res.push_back(chr(j));
                return true;
            }
        }

        for (int j = 0; j < ALPHA; j++) {
            if (charsets[cur].count(chr(j)) == 0) {
                continue;
            }
            res.push_back(chr(j));
            if (traverse(res, cur + 1, n, nodes[ptr].next[j])) {
                return true;
            }
            res.pop_back();
        }
        return false;
    }
public:
    int idx;
    int length;
    vector<set<char> > charsets;
    vector<TrieNode> nodes;
};

string solve(int n, int l, const vector<string>& words) {
    Trie trie(l);
    for (const auto& word: words) {
        trie.insert(word);
    }

    string res;
    if (!trie.traverse(res, 0, n, 0)) {
        return "-";
    }

    if (res.size() != l) {
        for (int j = res.size(); j < l; j++) {
            res.push_back(words[0][j]);
        }
    }

    /*
    for (const auto& word: words) {
        assert (word != res);
    }
    */
    return res;
}

int main() {
    int T;
    input(T);
    for (int case_ = 1; case_ <= T; case_++) {
        printf("Case #%d: ", case_);

        int n, l;
        input(n >> l);

        vector<string> words(n);
        for (int i = 0; i < n; i++) {
            input(words[i]);
        }

        print(solve(n, l, words));
    }
    return 0;
}