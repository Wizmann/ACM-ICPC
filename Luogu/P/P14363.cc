#include <bits/stdc++.h>
using namespace std;

// 字符映射：a~z -> 0~25, '#' -> 26
inline int idx(char c) {
    if (c == '#') return 26;
    return c - 'a';
}

const int MAXNODE = 5600000;   // 足够覆盖 L1 + 2n (<= ~5.4e6)
const int MAXE    = 5600000;   // 总边数 ~ 总字符数

struct AC {
    // 邻接表存Trie
    int head[MAXNODE];
    int to_[MAXE], nxt[MAXE], ch_[MAXE];
    int totNode = 0, totEdge = 0;

    int fail[MAXNODE];
    int val[MAXNODE];  // 该节点作为模式串结尾的个数（多规则叠加）
    long long sum[MAXNODE]; // val[u] + 所有 fail 祖先的 val

    vector<int> order; // BFS顺序（不含root）

    AC() {
        memset(head, 0, sizeof(head));
        memset(fail, 0, sizeof(fail));
        memset(val, 0, sizeof(val));
        memset(sum, 0, sizeof(sum));
        totNode = 0;
        totEdge = 0;
        order.clear();
        newNode(); // root = 0
    }

    int newNode() {
        int u = totNode++;
        head[u] = 0;
        fail[u] = 0;
        val[u] = 0;
        sum[u] = 0;
        return u;
    }

    // 在 u 下面找字符 c 的儿子，没有则返回 0
    inline int goEdge(int u, int c) const {
        for (int e = head[u]; e; e = nxt[e]) {
            if (ch_[e] == c) return to_[e];
        }
        return 0;
    }

    // 在 u 下面插入一条字符 c 的边到 v（v 已经创建）
    inline void addEdge(int u, int v, int c) {
        ++totEdge;
        to_[totEdge] = v;
        ch_[totEdge] = c;
        nxt[totEdge] = head[u];
        head[u] = totEdge;
    }

    // 插入一个模式串，val[终点]++
    void insert(const string &s) {
        int u = 0;
        for (char cc : s) {
            int c = idx(cc);
            int v = goEdge(u, c);
            if (!v) {
                v = newNode();
                addEdge(u, v, c);
            }
            u = v;
        }
        val[u]++;  // 多个规则模式一样，就叠加次数
    }

    // 建 fail + sum
    void build() {
        queue<int> q;
        // root 的所有儿子 fail=0
        for (int e = head[0]; e; e = nxt[e]) {
            int v = to_[e];
            fail[v] = 0;
            q.push(v);
        }

        order.clear();
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            // 遍历 u 的所有儿子
            for (int e = head[u]; e; e = nxt[e]) {
                int v = to_[e];
                int c = ch_[e];
                int f = fail[u];
                // 往 fail 链上跳
                while (f && !goEdge(f, c)) f = fail[f];
                int gf = goEdge(f, c);
                if (!gf) gf = 0;
                fail[v] = gf;
                q.push(v);
            }
        }

        // 先让 sum[u] = val[u]
        for (int i = 0; i < totNode; ++i) sum[i] = val[i];
        // 再按 BFS 顺序，把 fail 贡献向下推
        for (int u : order) {
            sum[u] += sum[fail[u]];
        }
    }

    // 在文本串 text 上跑 AC，返回所有模式出现次数之和
    long long query(const string &text) const {
        long long ans = 0;
        int u = 0;
        for (char cc : text) {
            int c = idx(cc);
            int v;
            while (true) {
                v = goEdge(u, c);
                if (v || !u) break;
                u = fail[u];
            }
            u = v;
            ans += sum[u];
        }
        return ans;
    }
};

// 把 (a,b) 交叉叠放成 A#mid1mid2#B
string encode_pair(const string &a, const string &b) {
    int L = (int)a.size();
    int p = 0;
    while (p < L && a[p] == b[p]) ++p;
    int s = 0;
    while (s < L - p && a[L - 1 - s] == b[L - 1 - s]) ++s;

    string res;
    res.reserve(L * 2 + 2);

    // 前缀
    res.append(a.begin(), a.begin() + p);
    // 分隔符
    res.push_back('#');
    // 中间部分
    res.append(a.begin() + p, a.begin() + (L - s));
    res.append(b.begin() + p, b.begin() + (L - s));
    // 分隔符
    res.push_back('#');
    // 后缀
    res.append(a.begin() + (L - s), a.end());

    return res;
}

AC ac;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    // 读规则，建 AC
    for (int i = 0; i < n; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1.size() != s2.size()) continue; // 理论上不会发生
        if (s1 == s2) continue;               // 不会让不同的串相互转换，直接丢掉
        string pat = encode_pair(s1, s2);
        ac.insert(pat);
    }

    ac.build();

    // 处理每个询问
    for (int j = 0; j < q; ++j) {
        string t1, t2;
        cin >> t1 >> t2;
        if (t1.size() != t2.size()) {
            cout << 0 << '\n';
            continue;
        }
        // 题目保证 t1 != t2，不过就算相等结果也会是 0
        string text = encode_pair(t1, t2);
        long long ans = ac.query(text);
        cout << ans << '\n';
    }

    return 0;
}

/*

^^^^^TEST^^^^^
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
-----------
2
0
$$$$TEST$$$$$

^^^^^TEST^^^^^
3 4
a b
b c
c d
aa bb
aa b
a c
b a
-----------
0
0
0
0
$$$$TEST$$$$$

*/
