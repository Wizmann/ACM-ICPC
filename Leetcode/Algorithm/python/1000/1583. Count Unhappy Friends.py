class Solution(object):
    def unhappyFriends(self, n, preferences, pairs):
        ps = [-1 for i in xrange(n)]
        for (a, b) in pairs:
            ps[a] = b
            ps[b] = a

        ds = [{} for i in xrange(n)]
        for i, pre in enumerate(preferences):
            m = len(pre)
            for p in pre:
                ds[i][p] = m
                m -= 1


        def check_unhappy(a, b):
            for c in preferences[a]:
                if c == b:
                    break
                d = ps[c]
                if ds[c].get(a, -1) > ds[c].get(d, -1):
                    return True
            return False

        st = set()
        for (a, b) in pairs:
            if check_unhappy(a, b):
                st.add(a)
            if check_unhappy(b, a):
                st.add(b)
        return len(st)

assert Solution().unhappyFriends(
        4,
        [[1, 3, 2], [2, 3, 0], [1, 3, 0], [0, 2, 1]],
        [[1, 3], [0, 2]]) == 4

