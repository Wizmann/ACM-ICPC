class Solution(object):
    def generateValidStrings(self, n, k):
        res = []
        chars = ['0'] * n

        def dfs(pos, prev_is_one, cost):
            if cost > k:
                return

            if pos == n:
                res.append(''.join(chars))
                return

            # 放 0
            chars[pos] = '0'
            dfs(pos + 1, False, cost)

            # 放 1：不能和前一个 1 相邻
            if not prev_is_one:
                new_cost = cost + pos
                if new_cost <= k:
                    chars[pos] = '1'
                    dfs(pos + 1, True, new_cost)
                    chars[pos] = '0'

        dfs(0, False, 0)
        return res
