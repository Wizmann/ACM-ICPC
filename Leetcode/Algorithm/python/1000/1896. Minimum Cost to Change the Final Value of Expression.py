INF = 10 ** 10
from copy import deepcopy

class Solution(object):
    def __init__(self):
        self.fun = [
            lambda x, y : x & y,
            lambda x, y : x | y,
        ]
        self.op_map = {'&': 0, '|': 1}

    def minOperationsToFlip(self, expression):
        n = len(expression)
        self.p = [-1 for i in xrange(n)]
        st = []
        for i in xrange(n):
            if expression[i] == '(':
                st.append(i)
            elif expression[i] == ')':
                self.p[st.pop()] = i

        res = self.solve(expression, 0, n)
        assert min(res) == 0
        return max(res)

    def solve(self, expression, l, r):
        dp = {}
        op = 'x'
        n = len(expression)
        i = l
        while i < r:
            item = expression[i]
            if item in ['|', '&']:
                op = item
                i += 1
                continue

            if item not in ['0', '1']:
                ll = i + 1
                rr = self.p[i]
                cur = self.solve(expression, ll, rr)
                i = rr
                # print item, expression, i
            else:
                item = int(item)
                cur = [0, 0]
                cur[item ^ 1] = 1

            step0 = cur[0]
            step1 = cur[1]

            if not dp:
                assert op == 'x'
                dp[0] = step0
                dp[1] = step1
            else:
                assert op in '&|'
                op1 = self.op_map[op]
                op2 = self.op_map[op] ^ 1
                op_fun1 = self.fun[op1]
                op_fun2 = self.fun[op2]
                dp2 = {}
                for key, value in dp.items():
                    u1 = op_fun1(key, 0)
                    u2 = op_fun1(key, 1)
                    dp2[u1] = min(dp2.get(u1, INF), value + step0)
                    dp2[u2] = min(dp2.get(u2, INF), value + step1)

                    u3 = op_fun2(key, 0)
                    u4 = op_fun2(key, 1)
                    dp2[u3] = min(dp2.get(u3, INF), value + step0 + 1)
                    dp2[u4] = min(dp2.get(u4, INF), value + step1 + 1)
                dp = dp2
            i += 1
        # print expression, dp
        return [dp[0], dp[1]]

assert Solution().minOperationsToFlip("(0|(1|0&1))") == 1
assert Solution().minOperationsToFlip("1&(0|1)") == 1
assert Solution().minOperationsToFlip("1&1") == 1
assert Solution().minOperationsToFlip("(0&0)&(0&0&0)") == 3
