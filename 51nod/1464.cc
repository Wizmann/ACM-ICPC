#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x
#define checkpoint() print(__LINE__)

const int SIZE = 5555;

struct Node {
    int next[2];
    int parent;
    int is_end;
};

Node trie_nodes[SIZE * 4];
string s;
int n;
int idx;
int dp[SIZE][SIZE];
string path;

void get_half_palin() {
    for (int i = 0; i < n; i++) {
        for(int j = 0; i + j < n; j++) {
            int a = j;
            int b = j + i;
            if (s[a] != s[b]) {
                continue;
            }
            
            int aa = a + 2;
            int bb = b - 2;
            
            if (bb <= aa) {
                dp[a][b] = 1;
            } else {
                dp[a][b] |= dp[aa][bb];
            }
        }
    }
    
    /*
    vector<string> palins;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j]) {
                palins.push_back(s.substr(i, j - i + 1));
            }
        }
    }
    sort(palins.begin(), palins.end());
    for (auto& p: palins) {
        print(p);
    }
    */
}

void do_add_str(int p, int q) {
    int ptr = 0;
    for (int i = p; i <= q; i++) {
        int c = s[i] - 'a';

        if (trie_nodes[ptr].next[c] == 0) {
            trie_nodes[ptr].next[c] = ++idx;
            trie_nodes[idx].parent = ptr;
        }
        ptr = trie_nodes[ptr].next[c];
        if (dp[p][i]) {
            trie_nodes[ptr].is_end++;
        }
    }
}

void add_str(int p) {
    int q = n - 1;
    while (q >= p) {
        if (dp[p][q]) {
            break;
        }
        q--;
    }
    do_add_str(p, q);
}

void build_trie() {
    for (int i = 0; i < n; i++) {
        add_str(i);
    }
}

int dfs(int cur, int& cnt) {
    if (trie_nodes[cur].is_end) {
        cnt -= trie_nodes[cur].is_end;
    }
    if (cnt <= 0) {
        return cur;
    }
    
    if (trie_nodes[cur].next[0] != 0) {
        path.push_back('a');
        int x = dfs(trie_nodes[cur].next[0], cnt);
        path.pop_back();
        if (x != 0) {
            return x;
        }
    }

    if (trie_nodes[cur].next[1] != 0) {
        path.push_back('b');
        int y = dfs(trie_nodes[cur].next[1], cnt);
        path.pop_back();
        if (y != 0) {
            return y;
        }
    }

    return 0;
}

string solve(int k) {
    int p = dfs(0, k);
    string res;
    while (p) {
        int q = trie_nodes[p].parent;
        if (trie_nodes[q].next[0] == p) {
            res += 'a';
        } else {
            res += 'b';
        }
        p = q;
    }
    reverse(res.begin(), res.end());
    return res;
}


int main() {
    freopen("input.txt", "r", stdin);
    idx = 0;
    memset(trie_nodes, 0, sizeof(trie_nodes));
    input(s);
    
    // checkpoint();
    
    n = s.size();
    get_half_palin();
    
    // checkpoint();
    
    build_trie();
    
    // checkpoint();

    int k;
    input(k);
    print(solve(k));

    return 0;
}
