from collections import deque
class Solution(object):
    def longestSemiRepetitiveSubstring(self, s):
        n = len(s)
        st = deque()
        p = 0
        flag = False
        res = 0
        tot = 0
        while p < n:
            cur = s[p]
            cnt = 0
            while p < n and s[p] == cur:
                cnt += 1
                p += 1

            if cnt == 1:
                res = max(res, tot + 1)
                st.append(1)
                tot += 1
            elif cnt == 2:
                res = max(res, tot + 1)
                while st and flag:
                    if st[0] > 1:
                        tot -= st[0]
                        st[0] = 1
                        tot += 1
                        flag = False
                    else:
                        tot -= st.popleft()
                res = max(res, tot + 2)
                flag = True
                st.append(2)
                tot += 2
            else:
                res = max(res, tot + 2 if not flag else tot + 1)
                st = deque([2])
                tot = 2
                flag = True
        return res


'''
^^^^TEST^^^^
"52233"
----------------
4
$$$$TEST$$$$

^^^^TEST^^^^
"5494"
----------------
4
$$$$TEST$$$$

^^^^TEST^^^^
"1111111"
----------------
2
$$$$TEST$$$$

'''
