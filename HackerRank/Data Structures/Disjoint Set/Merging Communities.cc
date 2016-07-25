#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

struct Node {
    int father;
    int size;
    
    Node(): father(-1), size(-1) {}
    Node(int father_, int size_): father(father_), size(size_) {}
};

int n, m;

vector<Node> nodes;

int find_father(int x) {
    if (nodes[x].father == x) {
        return x;
    }
    return nodes[x].father = find_father(nodes[x].father);
}

int main() {
    input(n >> m);
    nodes = vector<Node>(n + 1);
    
    for (int i = 0; i <= n; i++) {
        nodes[i] = Node(i, 1);
    }
    
    string cmd;
    int a, b;
    while (m--) {
        input(cmd);
        if (cmd == "Q") {
            input(a);
            int f = find_father(a);
            print(nodes[f].size);
        } else {
            input(a >> b);
            int fa = find_father(a);
            int fb = find_father(b);
            if (fa != fb) {
                nodes[fb].size += nodes[fa].size;
                nodes[fa].father = fb;
            }
        }
    }
    return 0;
}

