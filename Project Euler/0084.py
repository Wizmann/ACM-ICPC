import math
from collections import defaultdict

# --- 棋盘常量 ---
N = 40
GO = 0
JAIL = 10
G2J = 30
CC = {2, 17, 33}
CH = {7, 22, 36}
R = [5, 15, 25, 35]
U = [12, 28]

# --- 骰子配置：两颗 D 面骰（本题要 2d4）---
D = 4
dice_outcomes = []
for a in range(1, D + 1):
    for b in range(1, D + 1):
        s = a + b
        is_double = (a == b)
        dice_outcomes.append((s, is_double, 1.0 / (D * D)))

def next_rail(pos):
    for r in R:
        if r > pos % N:
            return r
    return R[0]

def next_util(pos):
    for u in U:
        if u > pos % N:
            return u
    return U[0]

def apply_square_effects_once(pos):
    """
    对“落在某格子后”的即时效果展开一次（卡牌独立等概率抽取的近似）。
    CH 的 back-3 会落到新格，继续展开（递归地只对卡牌/传送），
    直到落在“普通格”或已被送监狱。
    """
    # G2J: 直接送监狱
    if pos == G2J:
        return {JAIL: 1.0}

    # CC: 2/16 动作（GO/JAIL），其余不动
    if pos in CC:
        return {GO: 1.0/16*1, JAIL: 1.0/16*1, pos: 14.0/16}

    # CH: 10/16 动作，6/16 不动
    if pos in CH:
        out = defaultdict(float)
        # 6 张不动
        out[pos] += 6.0/16
        p = 1.0/16
        # 6 张定点
        out[GO]  += p
        out[JAIL]+= p
        out[11]  += p  # C1
        out[24]  += p  # E3
        out[39]  += p  # H2
        out[5]   += p  # R1
        # 2 张 next R
        out[next_rail(pos)] += p
        out[next_rail(pos)] += p
        # 1 张 next U
        out[next_util(pos)] += p
        # 1 张 back 3（可能再次触发 CC/CH/G2J，需要继续展开）
        back3 = (pos - 3) % N
        for q, qp in apply_square_effects_once(back3).items():
            out[q] += p * qp
        return dict(out)

    # 普通格
    return {pos: 1.0}

def end_distribution_after_one_roll(start_pos, dice_sum, is_double):
    """
    从 start_pos 前进 dice_sum 后，应用所有即时效果（含 CC/CH 连锁、G2J），
    返回 {终点格: 概率}。
    注意：这里只处理棋盘效果；是否继续掷骰由“分层矩阵”负责。
    """
    new_pos = (start_pos + dice_sum) % N
    return apply_square_effects_once(new_pos)

# ---------- 构造“单次掷骰”的分层转移块 ----------
# 层含义：0=当前非连续双骰、1=已连掷1次双骰、2=已连掷2次双骰
# 我们需要 6 个 40x40 的块：
# A: layer0 --(非双骰)--> layer0
# B: layer0 --(双骰)-->   layer1
# C: layer1 --(非双骰)--> layer0
# D: layer1 --(双骰)-->   layer2
# E: layer2 --(非双骰)--> layer0
# F: layer2 --(双骰)-->   layer0（第三次双骰：直接入狱，且“不前进、不触发卡牌”，概率质量全部进 JAIL）

def zero_mat(n):
    return [[0.0 for _ in range(n)] for __ in range(n)]

def add_to_row(mat, r, col, val):
    mat[r][col] += val

def build_layer_blocks():
    A = zero_mat(N)
    B = zero_mat(N)
    C = zero_mat(N)
    Dm = zero_mat(N)  # D 是关键字，避免覆盖
    E = zero_mat(N)
    F = zero_mat(N)   # 第三次双骰，全部去 JAIL

    p_double_total = sum(p for _, is_d, p in dice_outcomes if is_d)

    for s in range(N):
        # 非双骰：普通前进+效果
        for dice_sum, is_d, p in dice_outcomes:
            if not is_d:
                dist = end_distribution_after_one_roll(s, dice_sum, is_d)
                for t, qp in dist.items():
                    add_to_row(A, s, t, p * qp)   # layer0 -> layer0
                    add_to_row(C, s, t, p * qp)   # layer1 -> layer0
                    add_to_row(E, s, t, p * qp)   # layer2 -> layer0

        # layer2 的“双骰第三次”：直接入狱（不前进，不触发卡牌）
        add_to_row(F, s, JAIL, p_double_total)

        # 双骰（非第三次）：正常前进+效果
        for dice_sum, is_d, p in dice_outcomes:
            if is_d:
                dist = end_distribution_after_one_roll(s, dice_sum, is_d)
                for t, qp in dist.items():
                    add_to_row(B,  s, t, p * qp)  # layer0 -> layer1
                    add_to_row(Dm, s, t, p * qp)  # layer1 -> layer2

    return A, B, C, Dm, E, F

# ---------- 由分层块合成“整回合”的 40x40 转移矩阵 ----------
# 回合内最多掷 3 次（第三次双骰直接入狱）：
# 终止于 layer0 的路径：
# 1) 直接非双骰：         A
# 2) 双骰后非双骰：       B @ C
# 3) 双骰、双骰、非双骰： B @ D @ E
# 4) 双骰、双骰、再双骰： B @ D @ F   （F 把质量全部送到 JAIL）
def matmul(X, Y):
    n = len(X)
    m = len(Y[0])
    k = len(Y)
    out = [[0.0 for _ in range(m)] for __ in range(n)]
    for i in range(n):
        Xi = X[i]
        for t in range(m):
            s = 0.0
            for j in range(k):
                s += Xi[j] * Y[j][t]
            out[i][t] = s
    return out

def matadd(*Ms):
    n = len(Ms[0])
    m = len(Ms[0][0])
    out = [[0.0 for _ in range(m)] for __ in range(n)]
    for M in Ms:
        for i in range(n):
            row_i = M[i]
            out_i = out[i]
            for j in range(m):
                out_i[j] += row_i[j]
    return out

def build_turn_matrix():
    A, B, C, Dm, E, F = build_layer_blocks()
    BC   = matmul(B, C)
    BDE  = matmul(matmul(B, Dm), E)
    BDF  = matmul(matmul(B, Dm), F)
    P = matadd(A, BC, BDE, BDF)  # 40x40
    # 数值微误差归一化每行
    for i in range(N):
        s = sum(P[i])
        if s > 0:
            for j in range(N):
                P[i][j] /= s
        else:
            P[i][i] = 1.0
    return P

# ---------- 高斯消元解平稳分布 π，满足 π = π P，且 sum π = 1 ----------
def solve_stationary(P):
    n = len(P)
    # 构造 A = (P^T - I)，并把最后一行替换为全1；b 最后一项为 1
    A = [[0.0 for _ in range(n)] for __ in range(n)]
    for i in range(n):
        for j in range(n):
            A[i][j] = P[j][i]
        A[i][i] -= 1.0
    for j in range(n):
        A[n-1][j] = 1.0
    b = [0.0]*n
    b[n-1] = 1.0

    # 带部分选主元的高斯消元
    for col in range(n):
        pivot = max(range(col, n), key=lambda r: abs(A[r][col]))
        if abs(A[pivot][col]) < 1e-15:
            continue
        if pivot != col:
            A[col], A[pivot] = A[pivot], A[col]
            b[col], b[pivot] = b[pivot], b[col]
        fac = A[col][col]
        for j in range(col, n):
            A[col][j] /= fac
        b[col] /= fac
        for r in range(n):
            if r == col: continue
            f = A[r][col]
            if f == 0:  continue
            for j in range(col, n):
                A[r][j] -= f * A[col][j]
            b[r] -= f * b[col]
    return b  # 即 π

def monopoly_modal_string_2d4():
    P = build_turn_matrix()       # 整回合 40×40 矩阵（已把连掷折叠）
    pi = solve_stationary(P)      # 平稳分布（回合结束时所在格子的概率）
    top3 = sorted(enumerate(pi), key=lambda x: (-x[1], x[0]))[:3]
    modal = "".join(f"{i:02d}" for i, _ in top3)
    return pi, top3, modal

if __name__ == "__main__":
    pi, top3, modal = monopoly_modal_string_2d4()
    print("Top 3 squares (index, prob%):")
    for i, p in top3:
        print(f"{i:02d}  {p*100:.3f}%")
    print("Modal string:", modal)

