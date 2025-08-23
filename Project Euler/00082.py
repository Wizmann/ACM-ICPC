from typing import List
import sys
import math

def parse_matrix_from_stdin() -> List[List[int]]:
    """
    从标准输入读取多行，每行用英文逗号分隔整数，构成矩阵。
    空行会被忽略；各行列数必须一致。
    """
    lines = [line.strip() for line in sys.stdin.read().splitlines()]
    rows = []
    for ln in lines:
        if not ln:
            continue
        rows.append([int(x.strip()) for x in ln.split(",") if x.strip() != ""])
    if not rows:
        return []
    m = len(rows[0])
    for r in rows:
        if len(r) != m:
            raise ValueError("各行列数不一致，请检查输入。")
    return rows

def build_col_prefix_sums(matrix: List[List[int]]) -> List[List[int]]:
    """
    列前缀和：col_ps[c][i] = 第 c 列前 i 项之和（i 从 0..n）
    求任意闭区间和：sum(a..b) = col_ps[c][max+1] - col_ps[c][min]
    """
    n = len(matrix)
    m = len(matrix[0]) if n > 0 else 0
    col_ps = [[0]*(n+1) for _ in range(m)]
    for c in range(m):
        s = 0
        for i in range(n):
            s += matrix[i][c]
            col_ps[c][i+1] = s
    return col_ps

def col_range_sum(col_ps: List[List[int]], c: int, a: int, b: int) -> int:
    """
    返回第 c 列从行 a 到行 b（含）的和；a、b 无序（即自动按 min..max 取和）
    """
    lo, hi = (a, b) if a <= b else (b, a)
    return col_ps[c][hi+1] - col_ps[c][lo]

def compute_dp(matrix: List[List[int]]) -> List[List[int]]:
    """
    计算：
      dp[i][j] = min_k ( dp[k][j-1] + min_{x between i and k}(
                        sum(matrix[k..x][j-1]) + sum(matrix[x..i][j]) ) ) - matrix[i][j]

    这里 “between i and k” 表示 x ∈ [min(i,k)..max(i,k)]，
    两个区间和都按无序端点求和，因而同时覆盖 k<=x<=i 和 i<=x<=k。
    复杂度 ~ O(m * n^3)。
    边界：dp[*][0] = 0（如需更严格边界可自行替换）。
    """
    n = len(matrix)
    if n == 0:
        return []
    m = len(matrix[0])
    col_ps = build_col_prefix_sums(matrix)

    dp = [[0]*m for _ in range(n)]
    for i in range(n):
        dp[i][0] = matrix[i][0]  # 若你有别的定义，改这里

    INF = math.inf
    for j in range(1, m):
        for i in range(n):
            best = INF
            # k 遍历全体行，允许 k 在 i 的任一侧
            for k in range(0, n):
                inner_best = INF
                # x 取介于 i 与 k 之间的所有行（含端点）
                lo = i if i < k else k
                hi = k if k > i else i
                for x in range(lo, hi + 1):
                    # 两段区间和都用“无序端点”的闭区间求和
                    sum_left  = col_range_sum(col_ps, j-1, k, x)  # matrix[k..x][j-1]
                    sum_right = col_range_sum(col_ps, j,   x, i)  # matrix[x..i][j]
                    val = dp[k][j-1] + (sum_left + sum_right)
                    if val < inner_best:
                        inner_best = val
                candidate = inner_best - matrix[k][j - 1]
                if candidate < best:
                    best = candidate
            dp[i][j] = best
    return dp

def main():
    matrix = parse_matrix_from_stdin()
    if not matrix:
        print("[]")
        return
    dp = compute_dp(matrix)
    mini = math.inf
    for row in dp:
        mini = min(mini, row[-1])
    print(mini)


if __name__ == "__main__":
    main()

