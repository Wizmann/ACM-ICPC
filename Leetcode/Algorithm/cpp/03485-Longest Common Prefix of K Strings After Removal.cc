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

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

constexpr int ALPHA = 26;
constexpr int INF = 0x3f3f3f3f;

class Trie {
    struct TrieNode {
        vector<int> nxt;
        int cnt;
        int maxi;

        TrieNode() : nxt(ALPHA, -1), cnt(0), maxi(-INF) {}
    };
public:
    Trie() : nodes(1) {}
    void insert(const std::string& str, const int k) { do_insert(ROOT, str, 0, k); }
    int query(const std::string& str, const int k) { return do_query(ROOT, str, 0, k); }
private:
    int do_insert(int root, const std::string& str, const int cur, const int k) {
        if (cur == (int)str.size()) {
            nodes[root].cnt++;
            if (nodes[root].cnt >= k) {
                return nodes[root].maxi = max(nodes[root].maxi, 0);
            }
            return -INF;
        }

        int c = str[cur] - 'a';
        assert(root < (int)nodes.size());
        assert(c < (int)nodes[root].nxt.size());
        if (nodes[root].nxt[c] == -1) {
            nodes[root].nxt[c] = nodes.size();
            nodes.emplace_back();
        }
        assert(root < (int)nodes.size());
        int nxt = nodes[root].nxt[c];
        nodes[root].cnt++;
        int maxi = do_insert(nxt, str, cur + 1, k);
        nodes[root].maxi = max(nodes[root].maxi, maxi + 1);
        if (nodes[root].cnt < k) {
            nodes[root].maxi = -INF;
        } else {
            nodes[root].maxi = max(nodes[root].maxi, 0);
        }
        return nodes[root].maxi;
    }

    int do_query(int root, const std::string& str, const int cur, const int k) {
        if (cur == (int)str.size()) {
            int maxi = -INF;
            if (nodes[root].cnt > k) {
                maxi = 0;
            }
            for (int i = 0; i < ALPHA; i++) {
                int nxt = nodes[root].nxt[i];
                if (nxt == -1) {
                    continue;
                }
                maxi = max(maxi, nodes[nxt].maxi + 1);
            }
            return maxi;
        }
        int maxi = 0;
        int c = str[cur] - 'a';
        for (int i = 0; i < ALPHA; i++) {
            if (c == i) {
                int nxt = nodes[root].nxt[c];
                if (nxt == -1) {
                    continue;
                }
                int cnt = nodes[nxt].cnt;
                if (cnt <= k) {
                    continue;
                }
                maxi = max(maxi, do_query(nxt, str, cur + 1, k) + 1);
            } else {
                int nxt = nodes[root].nxt[i];
                if (nxt == -1) {
                    continue;
                }
                maxi = max(maxi, nodes[nxt].maxi + 1);
            }
        }
        return maxi;
    }
private:
    static constexpr int ROOT = 0;
    std::vector<TrieNode> nodes;
};

class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        Trie trie;
        for (const auto& word : words) {
            trie.insert(word, k);
        }

        vector<int> ans;
        ans.reserve(words.size());
        for (const auto& word : words) {
            ans.push_back(trie.query(word, k));
        }
        return ans;
    }
};
