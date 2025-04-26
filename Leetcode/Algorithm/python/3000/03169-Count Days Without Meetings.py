class Solution(object):
    def countDays(self, days, meetings):
        events = []
        for (l, r) in meetings:
            events.append((l, +1))
            events.append((r + 1, -1))
        events.append((days + 1, 0))

        events.sort()

        cur = 0
        cnt = 0
        res = 0
        for (day, status) in events:
            if day != cur:
                if cnt == 0:
                    res += day - cur
                cur = day

            if day == cur:
                cnt += status

        return res - 1

# print Solution().countDays(days = 10, meetings = [[5,7],[1,3],[9,10]])

'''
^^^^^TEST^^^^
10
[[5,7],[1,3],[9,10]]
------------
2
$$$$TEST$$$$$

^^^^^TEST^^^^
5
[[2,4],[1,3]]
-----------
1
$$$$TEST$$$

^^^^^TEST^^^^
6
[[1,6]]
-----------
0
$$$$TEST$$$

'''
