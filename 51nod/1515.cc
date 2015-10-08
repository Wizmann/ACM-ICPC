#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

struct Command {
    int x, y, p;
};

const int SIZE = 123456;

int n;
int father[SIZE];
vector<Command> cmds;
vector<set<int> > not_equal;

void init() {
    for (int i = 0; i < SIZE; i++) {
        father[i] = i;
    }
    not_equal.resize(SIZE);
}

int find_father(int x) {
    if (x == father[x]) {
        return x;
    }
    return father[x] = find_father(father[x]);
}

// crucial point: **heuristic algorithm**
void do_union(int a, int b) {
    if (not_equal[a].size() > not_equal[b].size()) {
        swap(a, b);
    }
    father[a] = b;
    for (auto v: not_equal[a]) {
        not_equal[b].insert(v);
        not_equal[v].erase(a);
        not_equal[v].insert(b);
    }
    not_equal[a].clear();
}

void solve() {
    init();
    for (auto cmd: cmds) {
        int x = find_father(cmd.x);
        int y = find_father(cmd.y);
        if (x > y) {
            swap(x, y);
        }
        int p = cmd.p;
        
        if (p == 1) {
            if (x == y) {
                puts("YES");
            } else if (not_equal[x].find(y) == not_equal[x].end()) {
                do_union(x, y);
                puts("YES");
            } else {
                puts("NO");
            }
        } else {
            if (x == y) {
                puts("NO");
            } else if (not_equal[x].find(y) == not_equal[x].end()) {
                not_equal[x].insert(y);
                not_equal[y].insert(x);
                puts("YES");
            } else {
                puts("YES");
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int a, b, c;
    input(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &a, &b, &c);
        cmds.push_back({a, b, c});
        mp[a] = -1;
        mp[b] = -1;
    }

    int idx = 1;
    for (auto& p: mp) {
        p.second = idx++;
    }

    for (auto& cmd: cmds) {
        cmd.x = mp[cmd.x];
        cmd.y = mp[cmd.y];
    }

    solve();

    return 0;
}
