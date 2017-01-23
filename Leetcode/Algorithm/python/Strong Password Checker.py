import re

class Solution(object):
    def strongPasswordChecker(self, s):
        add_cnt = 0
        n = len(s)

        if not re.search(r'[A-Z]', s):
            add_cnt += 1
        if not re.search(r'[a-z]', s):
            add_cnt += 1
        if not re.search(r'[0-9]', s):
            add_cnt += 1

        repeated = [len(match[0] + match[1]) for match in re.findall(r"(.)(\1{2,})", s)]


        if n < 6:
            action = 0
            for item in repeated:
                action += item / 3
                n += item / 3

            while action < add_cnt:
                action += 1
                n += 1

            return action + max(0, 6 - n)
        
        del_action = 0
        rep_action = 0
        while n > 20 and repeated:
            repeated = filter(lambda x: x > 2, repeated)
            repeated.sort(key=lambda x: x % 3)
            for i, item in enumerate(repeated):
                if n <= 20:
                    break
                diff = 0
                if item % 3 == 0:
                    diff = min(n - 20, 1)
                elif item % 3 == 1:
                    diff = min(n - 20, 2)
                else:
                    diff = min(n - 20, 3)
                n -= diff
                del_action += diff
                repeated[i] -= diff

        for item in repeated:
            rep_action += item / 3

        while rep_action < add_cnt:
            rep_action += 1

        return del_action + rep_action + max(n - 20, 0)


assert Solution().strongPasswordChecker("1234567890123456Baaaaa") == 3
assert Solution().strongPasswordChecker("ababababababababaaaaa") == 3
assert Solution().strongPasswordChecker("AAAAA") == 2
assert Solution().strongPasswordChecker("abababababababababaaa") == 3
assert Solution().strongPasswordChecker("aaa") == 3
assert Solution().strongPasswordChecker("aaa123") == 1
assert Solution().strongPasswordChecker("ABABABABABABABABABAB1") == 2
