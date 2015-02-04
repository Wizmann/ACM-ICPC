#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x
#define err(x)   cerr << x << endl

const int BASE = 64;
const int SIZE = 64 * 64;

int g[SIZE][SIZE];
int iter[SIZE];
int father[SIZE];
int indeg[SIZE], outdeg[SIZE];
int n;
vector<int> ans;

int get_value(char c) {
    if ('a' <= c && c <= 'z') {
        return c - 'a';
    }
    if ('A' <= c && c <= 'Z') {
        return c - 'A' + 26;
    }
    if ('0' <= c && c <= '9') {
        return c - '0' + 52;
    }
    err("get_value_err:" << ' ' << c);
    return -1;
}

int get_char(int v) {
    if (0 <= v && v <= 25) {
        return 'a' + v;
    }
    if (26 <= v && v <= 51) {
        return 'A' + v - 26;
    }
    if (52 <= v && v <= 61) {
        return '0' + v - 52;
    }
    err("get_char_err" << ' ' << v);
    return -1;
}

int get_id(char a, char b) {
    int ia = get_value(a);
    int ib = get_value(b);
    return ia * BASE + ib;
}

void add_edge(const string& node_str) {
    int a = get_id(node_str[0], node_str[1]);
    int b = get_id(node_str[1], node_str[2]);
    g[a][b]++;
    outdeg[a]++;
    indeg[b]++;
}

int get_father(int x) {
    if (father[x] == x) {
        return x;
    }
    return father[x] = get_father(father[x]);
}

bool is_connected() {
    for (int i = 0; i < SIZE; i++) {
        father[i] = i;
    }
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (g[i][j]) {
                father[get_father(i)] = get_father(j);
            }
        }
    }
    set<int> st;
    for (int i = 0; i < SIZE; i++) {
        if (!indeg[i] && !outdeg[i]) {
            continue;
        }
        st.insert(get_father(i));
    }
    return st.size() == 1U;
}

int get_start_point() {
    if (!is_connected()) {
        return -1;
    }
    int a = 0;
    int b = 0;
    int c = 0;
    int res = -1;
    for (int i = 0; i < SIZE; i++) {
        if (outdeg[i] == indeg[i] + 1) {
            a++;
            res = i;
        }
        if (outdeg[i] == indeg[i] - 1) {
            c++;
        }
        if (outdeg[i] == indeg[i]) {
            b++;
        }
    }
    if (a == 1 && b == SIZE - 2 && c == 1) {
        return res;
    }
    if (a == 0 && b == SIZE) {
        return 0;
    }
    return -1;
}

void dfs(int p) {
    for (int i = iter[p]; i < SIZE; i++) {
        if (g[p][i]) {
            g[p][i]--;
            dfs(i);
        }
        iter[p]++;
    }
    ans.push_back(p);
}

void show_path(int st) {
    string res;

    for (auto u: ans) {
        u %= BASE;
        char c = get_char(u);
        res += c;
    }
    char a = get_char(st / BASE);
    res += a;
    reverse(res.begin(), res.end());
    print(res);
}

int main() {
    input(n);
    string node_str;
    for (int i = 0; i < n; i++) {
        input(node_str);
        add_edge(node_str);
    }
    int u = get_start_point();
    if (u == -1) {
        print("NO");
    } else {
        print("YES");
        if (u == 0) {
            u = get_id(node_str[0], node_str[1]);
        }
        dfs(u);
        show_path(u);
    }
    return 0;
}
