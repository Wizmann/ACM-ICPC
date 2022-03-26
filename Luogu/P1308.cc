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
const int DIGITS = 26;

class Trie {
public:
    Trie() {
        nodes.emplace_back();
    }

    void insert(const string& s, int pos) {
        do_insert(0, s, 0, pos);
    }

    bool query(const string& s, int& count, int& pos) {
        return do_query(0, s, 0, count, pos);
    }

private:
    void do_insert(int cur, const string& s, int p, int pos) {
        if ((int)s.size() == p) {
            nodes[cur].count++;
            if (nodes[cur].pos == -1) {
                nodes[cur].pos = pos;
            }
            return;
        }
        int c = s[p] - 'a';

        if (nodes[cur].next[c] == -1) {
            nodes[cur].next[c] = nodes.size();
            nodes.emplace_back();
        }
        int nxt = nodes[cur].next[c];
        do_insert(nxt, s, p + 1, pos);
    }

    bool do_query(int cur, const string& s, int p, int& count, int& pos) {
        assert(cur != -1);
        if ((int)s.size() == p) {
            if (!nodes[cur].count) {
                return false;
            }
            count = nodes[cur].count;
            pos = nodes[cur].pos;
            return true;
        }
        int c = s[p] - 'a';
        int nxt = nodes[cur].next[c];
        if (nxt == -1) {
            return false;
        }
        return do_query(nxt, s, p + 1, count, pos);
    }
private:
    struct TrieNode {
        TrieNode() : count(0), pos(-1), next(DIGITS, -1) {
            // pass
        }

        int count;
        int pos;
        vector<int> next;
    };

    int idx = 0;
    deque<TrieNode> nodes;
};

int main() {
    string needle;
    input(needle);
    int m = needle.size();

    for (int i = 0; i < m; i++) {
        char& c = needle[i];
        if ('A' <= c && c <= 'Z') {
            c ^= ('a' ^ 'A');
        }
    }
    Trie trie;

    string haystack;
    while (haystack.empty()) {
        getline(cin, haystack);
    }
    int n = haystack.size();

    string buffer;
    for (int i = 0; i <= n; i++) {
        if (haystack[i] == ' ' || haystack[i] == '\0') {
            // print(buffer);
            if (buffer.size()) {
                trie.insert(buffer, i - buffer.size());
            }
            buffer.clear();
        } else {
            char c = haystack[i];
            if ('A' <= c && c <= 'Z') {
                c ^= ('a' ^ 'A');
            }
            buffer.push_back(c);
        }
    }

    int count = 0;
    int pos = 0;
    if (!trie.query(needle, count, pos)) {
        puts("-1");
    } else {
        printf("%d %d\n", count, pos);
    }

    return 0;
}

/*

^^^TEST^^^
To
to be or not to be is a question
-----
2 0
$$$TEST$$$

^^^^TEST^^^
to
Did the Ottoman Empire lose its power at that time
-------
-1
$$$TEST$$$


*/
