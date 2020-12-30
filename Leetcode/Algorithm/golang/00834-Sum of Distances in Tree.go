import "fmt";

var ans []int;
var cnt []int;

func sumOfDistancesInTree(N int, edges [][]int) []int {
    ans = make([]int, N);
    cnt = make([]int, N);
    g := make([][]int, N);
    for i := 0; i < N - 1; i++ {
        a, b := edges[i][0], edges[i][1];
        g[a] = append(g[a], b);
        g[b] = append(g[b], a);
    }
    ans0, _ := dfs1(g, -1, 0);
    dfs2(g, N, ans0, -1, 0);
    return ans;
}

func dfs1(g [][]int, pre, cur int) (int, int) {
    m := len(g[cur]);
    sum := 0
    nodes := 1
    for i := 0; i < m; i++ {
        next := g[cur][i];
        if next == pre {
            continue;
        }
        a, b := dfs1(g, cur, next);
        sum += a + b
        nodes += b;
    }
    cnt[cur] = nodes;
    return sum, nodes;
}

func dfs2(g [][]int, n, u, pre, cur int) {
    v := 0;
    if pre == -1 {
        v = u;
    } else {
        v = u - cnt[cur] + (n - cnt[cur]);
    }
    ans[cur] = v;
    m := len(g[cur])
    for i := 0; i < m; i++ {
        next := g[cur][i];
        if next == pre {
            continue;
        }
        dfs2(g, n, v, cur, next)
    }
}
