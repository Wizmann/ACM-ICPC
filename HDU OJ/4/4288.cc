#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cassert>
#include <iostream>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 1 << 17;

class SegTree {
public:
    struct SegTreeNode {
        llint val[5];
        int sub;

        SegTreeNode() {
            memset(val, 0, sizeof(val));
        }
    };

    SegTree() {
        tree = vector<SegTreeNode>(SIZE * 2);
    }

    void add(int pos, int val) {
        int cur = pos + SIZE;
        tree[cur].sub = 1;
        tree[cur].val[1] = val;

        modify(parent(cur));
    }

    void del(int pos) {
        int cur = pos + SIZE;
        tree[cur].sub = 0;
        tree[cur].val[1] = 0;

        modify(parent(cur));
    }

    llint getSum(int x) {
        return tree[1].val[x];
    }

private:
    int left(int x) { return 2 * x; }
    int right(int x) { return 2 * x + 1; }
    int parent(int x) { return x / 2; }

    void modify(int pos) {
        while (pos > 0) {
            int lcnt = tree[left(pos)].sub;
            int rcnt = tree[right(pos)].sub;
            tree[pos].sub = lcnt + rcnt;

            for (int i = 0; i < 5; i++) {
                tree[pos].val[i] = 0;
            }

            for (int i = 0; i < 5; i++) {
                tree[pos].val[i] += tree[left(pos)].val[i];
                tree[pos].val[(i + lcnt) % 5] += tree[right(pos)].val[i];
            }

            pos = parent(pos);
        }
    }
private:
    vector<SegTreeNode> tree;
};

struct Command {
    char c;
    int value;
};

void printInt(llint x) {
    puts(to_string(x).c_str());
}

int main() {
    int n;
    while (input(n)) {
        vector<Command> cmds;

        map<int, int> mp;
        char buffer[10];
        int v;
        for (int i = 0; i < n; i++) {
            scanf("%s", buffer);
            if (*buffer == 'a') {
                scanf("%d", &v);
                cmds.push_back({'a', v});
                mp[v] = -1;
            } else if (*buffer == 'd') {
                scanf("%d", &v);
                cmds.push_back({'d', v});
                mp[v] = -1;
            } else if (*buffer == 's') {
                cmds.push_back({'s', -1});
            }
        }

        int idx = 1;
        int m = mp.size();
        for (auto& kv : mp) {
            kv.second = idx++;
        }

        SegTree stree;

        for (const auto& cmd : cmds) {
            if (cmd.c == 'a') {
                stree.add(mp[cmd.value], cmd.value);
            } else if (cmd.c == 'd') {
                stree.del(mp[cmd.value]);
            } else if (cmd.c == 's') {
                printInt(stree.getSum(3));
            } else {
                assert(false);
            }

            /*
            for (int i = 0; i < 5; i++) {
                printf("%lld ", stree.getSum(i));
            }
            puts("");
            puts("--");
            */
        }
    }
    return 0;
}
