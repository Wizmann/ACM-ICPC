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

const int SIZE = 123456;
const int ROOT = 0;
const int LENGTH = 20;
const int MASK = (1 << LENGTH) - 1;

struct TreeNode {
    int left;
    int right;
    int mark;

    TreeNode() {}
    TreeNode(int il, int ir): left(il), right(ir), mark(-1) {}
};

int idx;
int n;
vector<int> cows;
TreeNode tree[(1 << LENGTH) + 233];

void do_add(int pos, int value, int p, int mark) {
    if (p == -1) {
        tree[pos].mark = mark;
        return;
    }
    int u = value & (1 << p);

    if (u == 0) {
        if (tree[pos].left == -1) {
            tree[pos].left = ++idx;
        }
        int npos = tree[pos].left;
        do_add(npos, value ^ u, p - 1, mark);
    } else {
        if (tree[pos].right == -1) {
            tree[pos].right = ++idx;
        }
        int npos = tree[pos].right;
        do_add(npos, value ^ u, p - 1, mark);
    }
}

int do_search(int pos, int value, int p, int& start) {
    if (p == -1) {
        start = tree[pos].mark;
        return value;
    }
    int u = value & (1 << p);
    if (u == 0) {
        if (tree[pos].right != -1) {
            int npos = tree[pos].right;
            return do_search(npos, value ^ (1 << p), p - 1, start);
        } else if (tree[pos].left != -1) {
            int npos = tree[pos].left;
            return do_search(npos, value, p - 1, start);
        }
    } else {
        if (tree[pos].left != -1) {
            int npos = tree[pos].left;
            return do_search(npos, value, p - 1, start);
        } else if (tree[pos].right != -1) {
            int npos = tree[pos].right;
            return do_search(npos, value ^ (1 << p), p - 1, start);
        }
    }
    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    int cow;
    while (input(n)) {
        idx = 0;
        cows.clear();
        memset(tree, -1, sizeof(tree));
        for (int i = 0; i < n; i++) {
            input(cow);
            cows.push_back(cow);
        }
        int ans = 0;
        int xor_sum = 0;

        int st = -1;
        int end = -1;

        for (int i = 0; i < n; i++) {
            xor_sum ^= cows[i];

            if (xor_sum > ans) {
                ans = xor_sum;
                st = end = i;
            }

            int start = 0;
            int u = do_search(ROOT, xor_sum, LENGTH, start);
            //print(u);
            if (u > ans) {
                ans = u;
                st = start;
                end = i;
            }
            do_add(ROOT, xor_sum, LENGTH, i);
        }
        printf("%d %d %d\n", ans, st + 2, end + 1);
    }
    return 0;
}
