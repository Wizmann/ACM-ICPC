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

class BinaryTrie {
public:
    BinaryTrie(int bits_) : bits(bits_) {
        tree.emplace_back();
    }

    void add(int x) {
        int cur = root;
        for (int i = bits - 1; i >= 0; i--) {
            int y = (x & (1 << i)) ? 1: 0;
            if (tree[cur].next[y] == -1) {
                tree[cur].next[y] = tree.size();
                tree.emplace_back();
            }
            cur = tree[cur].next[y];
        }
        tree[cur].leaf = true;
    }

    int get_max(int x) {
        int cur = root;
        int res = 0;
        for (int i = bits - 1; i >= 0; i--) {
            int y = (x & (1 << i)) ? 1 : 0;
            if (tree[cur].next[y ^ 1] != -1) {
                cur = tree[cur].next[y ^ 1];
                res |= (1 << i);
            } else if (tree[cur].next[y] != -1) {
                cur = tree[cur].next[y];
            } else {
                return -INF;
            }
        }

        // assert(tree[cur].leaf);
        return res;
    }
private:
    struct BinaryTrieNode {
        int next[2] = {-1, -1};
        bool leaf = false;
    };
private:
    const int root = 0;
    int bits;
    vector<BinaryTrieNode> tree;
};

int n;
vector<int> ns;

int main() {
    input(n);
    n--;
    ns.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ns[i]);
        ns[i] ^= ns[i - 1];
    }

    BinaryTrie trie(32);
    trie.add(0);
    for (int i = 1; i <= n; i++) {
        trie.add(ns[i]);
    }

    int res = -1;
    for (int b0 = 0; b0 <= n; b0++) {
        int maxi = trie.get_max(b0);
        if (maxi == n) {
            res = b0;
            break;
        }
    }
    assert(res != -1);
    
    printf("%d", res);
    for (int i = 1; i <= n; i++) {
        printf(" %d", ns[i] ^ res);
    }
    puts("");

    return 0;
}

/*

^^^TEST^^^
4
2 1 2
-----
0 2 3 1 
$$$TEST$$$

^^^TEST^^^
6
1 6 1 4 1
-----
2 3 5 4 0 1 
$$$TEST$$$

*/
