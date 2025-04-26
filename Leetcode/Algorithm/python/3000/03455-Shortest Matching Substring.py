#coding=utf-8
def robin_karp(s, t):
    # 设置基础的哈希参数
    d = 29  # 字符集大小，假设为小写字母a-z
    MOD = int(1e9 + 7)  # 取模的质数

    m = len(t)  # 模式串的长度
    n = len(s)  # 主串的长度

    if m > n:
        return []

    # 计算 t 的哈希值
    t_hash = 0
    for i in xrange(m):
        t_hash = (d * t_hash + ord(t[i]) - ord('a') + 1) % MOD

    # 计算 s 的第一个滑动窗口的哈希值
    s_hash = 0
    for i in xrange(m):
        s_hash = (d * s_hash + ord(s[i]) - ord('a') + 1) % MOD

    # 计算 d^m % MOD, 用于后续的哈希值更新
    h = 1
    for i in xrange(m - 1):
        h = (h * d) % MOD

    # 保存所有匹配的开始位置
    result = []

    # 滑动窗口遍历 s
    for i in xrange(n - m + 1):
        # 如果哈希值相等，进一步验证是否真是匹配（避免哈希冲突）
        if s_hash == t_hash:
            result.append(i)

        # 计算下一个滑动窗口的哈希值
        if i < n - m:
            s_hash = (d * (s_hash - (ord(s[i]) - ord('a') + 1) * h % MOD) + (ord(s[i + m]) - ord('a') + 1)) % MOD
            s_hash = ((s_hash % MOD) + MOD) % MOD

    return result

INF = 10 ** 10

class Solution(object):
    def shortestMatchingSubstring(self, s, p):
        n = len(s)
        patterns = p.split('*')
        pos = []
        for pattern in patterns:
            if not pattern:
                pos.append(range(n + 1))
            else:
                pos.append(robin_karp(s, pattern))
        # print pos
        res = INF
        p0, p1, p2 = 0, 0, 0
        while p0 < len(pos[0]) and p1 < len(pos[1]) and p2 < len(pos[2]):
            nxt = pos[0][p0] + len(patterns[0])
            while p1 < len(pos[1]) and nxt > pos[1][p1]:
                p1 += 1
            if p1 >= len(pos[1]):
                break
            nxt = pos[1][p1] + len(patterns[1])
            while p2 < len(pos[2]) and nxt > pos[2][p2]:
                p2 += 1
            if p2 >= len(pos[2]):
                break
            nxt = pos[2][p2] + len(patterns[2])
            res = min(res, nxt - pos[0][p0])
            p0 += 1
        if res >= INF:
            res = -1
        return res

# assert Solution().shortestMatchingSubstring("abaacbaecebce", "ba*c*ce") == 8
# assert Solution().shortestMatchingSubstring("abcd", "cd**") == 2
