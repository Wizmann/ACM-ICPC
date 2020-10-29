// Result: 2020-10-29 23:50:05 Accepted    2665    577MS   24884K  3036 B  G++ Wizmann
// 题意：
// 给定长度为n的数组A[1...n]和m个查询
// 每个查询给定l, r, k。求A[l...r]中第k大的数是多少。
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int N = 100010;

const int INF = 0x3f3f3f3f;

class PersistentSegTree {
    struct TreeNode {
        TreeNode(): sum(0), L_son(0), R_son(0) {}
        int sum, L_son, R_son;
    };

public:
    // 一定要在初始化时确定vector<TreeNode>的大小, 否则会因为mem re-alloc造成奇怪的问题
    // n * 19为经验值，可根据题目要求随时更新
    PersistentSegTree(int n): cnt(0), tree(n * 19) {
        // pass
    }

    int Insert(int pre_root, int pos, int L, int R) {
        //从根节点往下更新到叶子，新建立出一路更新的节点，这样就是一颗新树了。
        int root = CreateNode(tree[pre_root].sum + 1, tree[pre_root].L_son, tree[pre_root].R_son);
        if (L == R) {
            return root;
        }
        int M = (L + R) >> 1;
        if (pos <= M) {
            tree[root].L_son = Insert(tree[pre_root].L_son, pos, L, M);
        } else {
            tree[root].R_son = Insert(tree[pre_root].R_son, pos, M + 1, R);
        }
        return root;
    }

    int QueryKthElement(int start, int end, int L, int R, int k) {
        if (L == R) {
            return L;
        }
        int M = (L + R) >> 1;
        //下面计算的sum就是当前询问的区间中，左儿子中的元素个数。
        int sum = tree[tree[end].L_son].sum - tree[tree[start].L_son].sum;
        // print(start << ' ' << end << ' ' << tree[tree[end].L_son].sum << ' ' << tree[tree[start].L_son].sum);
        if (k <= sum) {
            return QueryKthElement(tree[start].L_son, tree[end].L_son, L, M, k);
        } else {
            return QueryKthElement(tree[start].R_son, tree[end].R_son, M + 1, R, k - sum);
        }
    }

private:
    inline int CreateNode(int sum, int L_son, int R_son) {
        int idx = ++cnt;
        tree[idx].sum = sum;
        tree[idx].L_son = L_son;
        tree[idx].R_son = R_son;
        return idx;
    }

public:
    int cnt;
    vector<TreeNode> tree;
};


//记录原数组、排序后的数组
int nums[N], sorted[N];

int main()
{
    int T;
    int n, m;
    input(T);
    while (T--) {
        input(n >> m);
        auto pst = PersistentSegTree(n);

        for (int i = 1; i <= n; i++) {
            scanf("%d", &nums[i]);
            sorted[i] = nums[i];
        }
        sort(sorted + 1, sorted + 1 + n);
        int num = unique(sorted + 1, sorted + n + 1) - (sorted + 1);

        // 每个元素对应的根节点
        vector<int> root(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            //实际上是对每个元素建立了一颗线段树，保存其根节点
            int pos = lower_bound(sorted + 1, sorted + num + 1, nums[i]) - sorted;
            root[i] = pst.Insert(root[i - 1], pos, 1, num);
        }
        int l, r, k;
        while (m--) {
            scanf("%d%d%d", &l, &r, &k);
            int pos = pst.QueryKthElement(root[l - 1], root[r], 1, num, k);
            printf("%d\n", sorted[pos]);
        }
    }
    return 0;
}

/*
^^^TEST^^^
1 
10 1 
1 4 2 3 5 6 7 8 9 0 
1 3 2 
----
2
$$$TEST$$$
*/
