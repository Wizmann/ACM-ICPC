#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

struct Node {
    int type;
    int prefix;
    int repeat;
    int cur;

    llint pos;
};

vector<Node> nodes;
int n, q;

int solve(llint pos) {
    int l = 0;
    int r = n - 1;

    while (l <= r) {
        int mid = (l + r) >> 1;
        if (nodes[mid].pos > pos) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    
    if (nodes[r].type == 1) {
        return nodes[r].cur;
    } else {
        llint delta = pos - nodes[r].pos;
        delta %= nodes[r].prefix;
        return solve(delta);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int a, b, c;

    llint cur_pos = 0;
    input(n);
    for (int i = 0; i < n; i++) {
        input(a);
        if (a == 1) {
            input(b);
            nodes.push_back(Node{1, -1, -1, b, cur_pos});
            cur_pos += 1;
        } else {
            input(b >> c);
            nodes.push_back(Node{2, b, c, -1, cur_pos});
            cur_pos += static_cast<llint>(b) * c;
        }
    }
    input(q);
    llint pos;
    while (q--) {
        scanf("%lld", &pos);
        printf("%d ", solve(pos - 1));
    }
    puts("");

    return 0;
}

