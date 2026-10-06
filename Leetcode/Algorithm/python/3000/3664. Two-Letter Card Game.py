from collections import defaultdict

class Solution(object):
    def score(self, cards, x):
        d1 = defaultdict(int)
        d2 = defaultdict(int)
        c = 0
        for card in cards:
            if card == x + x:
                c += 1
            elif card[0] == x:
                d1[card[1]] += 1
            elif card[1] == x:
                d2[card[0]] += 1
        tot = 0
        u1, v1 = self.calc(d1)
        u2, v2 = self.calc(d2)
        tot += u1 + u2
        print u1, v1, u2, v2, c

        tot += min(v1, c)
        c -= min(v1, c)
        tot += min(v2, c)
        c -= min(v2, c)

        print u1, v1, u2, v2, c, tot

        u3 = (min(u1 * 2, c) / 2) * 2
        tot += u3 / 2
        c -= u3

        u4 = (min(u2 * 2, c) / 2) * 2
        tot += u4 / 2
        c -= u4

        return tot

    def calc(self, d):
        # d: Counter/默认dict，key 是非 x 的另一个字母，value 是这种牌的数量
        S = sum(d.values())                    # 该组总张数
        M = max(d.values()) if d else 0        # 出现最多的那一类数量
        u = min(S // 2, S - M)                 # 该组内最大可配对数
        rem = S - 2 * u                        # 组内剩余的单张数
        # 与你原先的断言保持一致的语义（u 等价于原先的 tot）
        assert(u * 2 + rem == S)
        return u, rem
