// 概率骗分解法
#pragma G++ optimize("O2")

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <random>
#include <functional>
#include <vector>
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

const int N = 100010;

vector<int> g[N];
vector<int> ns;
int n, m;
map<int, int> mp;
vector<int> rp;

unsigned long myrand(void) {
    return rand() * RAND_MAX + rand();
}

int do_mycount(int p, int v) {
    return upper_bound(g[v].begin(), g[v].end(), p) - g[v].begin();
}

int mycount(int l, int r, int v) {
    return do_mycount(r, v) - do_mycount(l - 1, v);
}

int TRY[] = {0, 1, 16, 27, 38, 48, 59, 70, 80, 91, 102, 113, 123, 134, 145, 155, 166, 177, 187, 198, 209};

int solve(int l, int r, int t) {
    int m = r - l + 1;
    double q = 1.0 * (r - l + 1) / t;
    int res = -1;

    set<int> st;
    int tot = 0;

    for (int i = 0; i <= TRY[t]; i++) {
        int p = l + myrand() % m;
        assert (l <= p && p <= r);

        int v = ns[p];
        if (v <= res) {
            continue;
        }

        if (st.count(v)) {
            continue;
        }
        st.insert(v);

        if (g[v].size() < q) {
            continue;
        }
        int cnt = mycount(l, r, v);
        tot += cnt;

        if (cnt > q) {
            res = max(res, v);
        }

        if (tot >= m) {
            break;
        }
    }

    if (res == -1) {
        return -1;
    }
    return rp[res];
}

int Scan() {
    int res = 0, flag = 0;
    char ch;
    if((ch = getchar()) == '-') flag = 1;
    else if(ch >= '0' && ch <= '9') res = ch - '0';
    while((ch = getchar()) >= '0' && ch <= '9')
        res = res * 10 + (ch - '0');
    return flag ? -res : res;
}
 
 
void Out(int a) {
    if(a < 0) { putchar('-'); a = -a; }
    if(a >= 10) Out(a / 10);
    putchar(a % 10 + '0');
}


int main() {
    srand(time(NULL));
    n = Scan();
    m = Scan();

    ns.resize(n);
    rp.resize(n);
    for (int i = 0; i < n; i++) {
        ns[i] = Scan();
        mp[ns[i]] = -1;
    }

    int idx = 0;
    for (auto& p: mp) {
        p.second = idx;
        assert(idx < n);
        rp[idx] = p.first;
        ++idx;
    }

    for (int i = 0; i < n; i++) {
        ns[i] = mp[ns[i]];
        g[ns[i]].push_back(i);
    }

    int l, r, t;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &l, &r, &t);
        l -= 1;
        r -= 1;
        Out(solve(l, r, t));
        puts("");
    }
    return 0;
}

/*
^^^TEST^^^
5 3
1 10 100 10 1
1 1 1
1 4 3
1 5 10
----
-1
10
100
$$$TEST$$$
^^^TEST^^^
8 3
1 2 1 4 4 5 3 3 
3 7 5
1 4 3
3 8 6
----
4
1
4
$$$TEST$$$

^^^TEST^^^
8 3
1 2 1 4 4 5 3 3 
3 7 1
1 4 3
3 8 6
----
-1
1
4
$$$TEST$$$

^^^TEST^^^
10 10
0 2 0 4 13 2 20 20 0 18 
3 7 2
4 4 1
1 1 3
4 8 1
4 9 2
3 4 3
3 5 1
5 6 8
1 5 6
3 6 8
---
-1
-1
0
-1
-1
4
-1
13
13
13
$$$TEST$$$

*/

// 主席树解法（正解）

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
    // Σ╕Çσ«ÜΦªüσ£¿σê¥σºïσîûµù╢τí«σ«Üvector<TreeNode>τÜäσñºσ░Å, σÉªσêÖΣ╝Üσ¢áΣ╕║mem re-allocΘÇáµêÉσÑçµÇ¬τÜäΘù«Θóÿ
    // n * 19Σ╕║τ╗ÅΘ¬îσÇ╝∩╝îσÅ»µá╣µì«Θóÿτ¢«Φªüµ▒éΘÜÅµù╢µ¢┤µû░
    PersistentSegTree(int n): cnt(0), tree(n * 19) {
        // pass
    }

    int Insert(int pre_root, int pos, int L, int R) {
        //Σ╗Äµá╣Φèéτé╣σ╛ÇΣ╕ïµ¢┤µû░σê░σÅ╢σ¡É∩╝îµû░σ╗║τ½ïσç║Σ╕ÇΦ╖»µ¢┤µû░τÜäΦèéτé╣∩╝îΦ┐Öµá╖σ░▒µÿ»Σ╕ÇΘóùµû░µáæΣ║åπÇé
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

    int Query(int start, int end, int L, int R, double t) {
        if (L == R) {
            if (tree[end].sum - tree[start].sum > t) {
                return L;
            } else {
                return -1;
            }
        }

        int res = -1;
        int M = (L + R) >> 1;
        if (tree[tree[end].L_son].sum - tree[tree[start].L_son].sum > t) {
            res = max(res, Query(tree[start].L_son, tree[end].L_son, L, M, t));
        }
        if (tree[tree[end].R_son].sum - tree[tree[start].R_son].sum > t) {
            res = max(res, Query(tree[start].R_son, tree[end].R_son, M + 1, R, t));
        }

        return res;
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


//Φ«░σ╜òσÄƒµò░τ╗äπÇüµÄÆσ║ÅσÉÄτÜäµò░τ╗ä
int nums[N], sorted[N];

int main()
{
    int n, m;
    input(n >> m);
    auto pst = PersistentSegTree(n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
        sorted[i] = nums[i];
    }
    sort(sorted + 1, sorted + 1 + n);
    int num = unique(sorted + 1, sorted + n + 1) - (sorted + 1);

    // µ»ÅΣ╕¬σàâτ┤áσ»╣σ║öτÜäµá╣Φèéτé╣
    vector<int> root(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        //σ«₧ΘÖàΣ╕èµÿ»σ»╣µ»ÅΣ╕¬σàâτ┤áσ╗║τ½ïΣ║åΣ╕ÇΘóùτ║┐µ«╡µáæ∩╝îΣ┐¥σ¡ÿσà╢µá╣Φèéτé╣
        int pos = lower_bound(sorted + 1, sorted + num + 1, nums[i]) - sorted;
        root[i] = pst.Insert(root[i - 1], pos, 1, num);
    }
    int l, r, k;
    while (m--) {
        scanf("%d%d%d", &l, &r, &k);
        int pos = pst.Query(root[l - 1], root[r], 1, num, 1.0 * (r - l + 1) / k);
        if (pos == -1) {
            puts("-1");
        } else {
            printf("%d\n", sorted[pos]);
        }
    }
    return 0;
}

/*
^^^TEST^^^
8 3
1 2 1 4 4 5 3 3 
3 7 5
1 4 3
3 8 6
----
4
1
4
$$$TEST$$$
*/

