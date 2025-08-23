#coding=utf-8
import sys
import heapq

def parse_matrix_from_stdin():
    """
    读取标准输入为矩阵。每行用英文逗号分隔整数。
    空行会被忽略；各行列数必须一致。
    """
    rows = []
    for line in sys.stdin.read().splitlines():
        line = line.strip()
        if not line:
            continue
        parts = [x.strip() for x in line.split(",") if x.strip() != ""]
        rows.append([int(x) for x in parts])
    if not rows:
        return []
    w = len(rows[0])
    for r in rows:
        if len(r) != w:
            raise ValueError("各行列数不一致，请检查输入。")
    return rows

def node_ids(i, j, W):
    """
    返回 (in_id, out_id)。
    用连续编号：每个格子占 2 个节点，偶数为入点，奇数为出点。
    """
    base = 2 * (i * W + j)
    return base, base + 1

def dijkstra_on_split_grid(matrix, include_goal_cost=True):
    """
    在“每格拆成入/出点”的图上跑最短路。
    include_goal_cost=True 表示终点设为 出(n-1,m-1)（计入终点权值）；
    若为 False，则终点设为 入(n-1,m-1)（不计入终点权值）。
    """
    if not matrix:
        return 0

    H, W = len(matrix), len(matrix[0])

    # 节点总数：每格 2 个点
    N = 2 * H * W

    # 起点：入(0,0)
    start_in, start_out = node_ids(0, 0, W)

    # 终点：默认用 出(H-1, W-1)
    goal_in, goal_out = node_ids(H - 1, W - 1, W)
    goal = goal_out if include_goal_cost else goal_in

    # Dijkstra：用“隐式图”生成边
    INF = 10**19
    dist = [INF] * N
    dist[start_in] = 0
    pq = [(0, start_in)]

    # 四邻方向
    dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    while pq:
        d, u = heapq.heappop(pq)
        if d != dist[u]:
            continue
        if u == goal:
            return d

        # 判断 u 是入点还是出点
        cell_idx = u // 2
        i, j = divmod(cell_idx, W)
        is_in = (u % 2 == 0)

        if is_in:
            # 入(i,j) -> 出(i,j)，代价为 matrix[i][j]
            _, out_id = node_ids(i, j, W)
            nd = d + matrix[i][j]
            if nd < dist[out_id]:
                dist[out_id] = nd
                heapq.heappush(pq, (nd, out_id))
        else:
            # 出(i,j) -> 入(ni,nj)（四邻），代价为 0
            for di, dj in dirs:
                ni, nj = i + di, j + dj
                if 0 <= ni < H and 0 <= nj < W:
                    in_id, _ = node_ids(ni, nj, W)
                    nd = d  # 权值 0
                    if nd < dist[in_id]:
                        dist[in_id] = nd
                        heapq.heappush(pq, (nd, in_id))

    return dist[goal]  # 若不可达，可能仍是 INF

def main():
    matrix = parse_matrix_from_stdin()
    if not matrix:
        print(0)
        return

    # include_goal_cost=True：终点设为出点，从而计入终点格子的权值
    ans = dijkstra_on_split_grid(matrix, include_goal_cost=True)
    print(ans if ans < 10**19 else "INF")

if __name__ == "__main__":
    main()

