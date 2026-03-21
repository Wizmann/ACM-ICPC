class Solution(object):
    def countFancy(self, l, r):

        def is_good(n):
            if n < 10:
                return True
            d = []
            while n > 0:
                d.append(n % 10)
                n //= 10
            d.reverse()
            return (all(d[i] < d[i+1] for i in range(len(d)-1)) or
                    all(d[i] > d[i+1] for i in range(len(d)-1)))

        good = set(i for i in range(200) if is_good(i))

        def solve(n):
            if n <= 0:
                return 0
            s = str(n)
            N = len(s)
            memo = {}

            # mode: 0 = inc, 1 = dec
            # last = -2 means monotonicity already broken
            # Returns (fancy_count, good_digit_sum_count)
            def dp(pos, last, ds, tight, started, mode):
                key = (pos, last, ds, tight, started, mode)
                if key in memo:
                    return memo[key]
                if pos == N:
                    if not started:
                        res = (0, 0)
                    else:
                        g = 1 if ds in good else 0
                        res = (1, g) if last != -2 else (g, g)
                    memo[key] = res
                    return res
                hi = int(s[pos]) if tight else 9
                tf, tg = 0, 0
                for d in range(hi + 1):
                    nt = tight and d == hi
                    if not started:
                        if d == 0:
                            f, g = dp(pos+1, -1, 0, nt, False, mode)
                        else:
                            f, g = dp(pos+1, d, d, nt, True, mode)
                    else:
                        if last == -2:
                            nl = -2
                        elif mode == 0 and d <= last:
                            nl = -2
                        elif mode == 1 and d >= last:
                            nl = -2
                        else:
                            nl = d
                        f, g = dp(pos+1, nl, ds+d, nt, True, mode)
                    tf += f; tg += g
                res = (tf, tg)
                memo[key] = res
                return res

            # fancy = f0 + f1 - c (good_digit_sum counted once in each mode, subtract one copy)
            f0, c = dp(0, -1, 0, True, False, 0)
            f1, _ = dp(0, -1, 0, True, False, 1)
            return f0 + f1 - c

        return solve(r) - solve(l - 1)
