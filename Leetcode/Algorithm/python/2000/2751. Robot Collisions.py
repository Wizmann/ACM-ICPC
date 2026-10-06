#coding=utf-8

class Robot(object):
    def __init__(self, i, p, h, d):
        self.i = i
        self.p = p
        self.h = h
        self.d = d

class Solution(object):
    def survivedRobotsHealths(self, positions, healths, directions):
        n = len(positions)
        robots = []
        for i in xrange(n):
            p1 = positions[i]
            h1 = healths[i]
            d1 = directions[i]
            robots.append(Robot(i, p1, h1, d1))
        robots.sort(key=lambda r: r.p)

        st = []
        for i in xrange(n):
            p1 = robots[i].p
            h1 = robots[i].h
            d1 = robots[i].d
            if d1 == 'R':
                st.append(i)
                continue
            while d1 == 'L' and st:
                pre = st.pop()
                h2 = robots[pre].h
                if h1 > h2:
                    h1 -= 1
                    robots[pre].h = -1
                elif h1 == h2:
                    h1 = -1
                    robots[pre].h = -1
                    break
                else:
                    h1 = -1
                    robots[pre].h -= 1
                    st.append(pre)
                    break
            robots[i].h = h1
        return map(lambda x: x.h, filter(lambda r: r.h != -1, sorted(robots, key=lambda r: r.i)))

'''
^^^^TEST^^^^
[5,4,3,2,1]
[2,17,9,15,10]
"RRRRR"
-------------------
[2,17,9,15,10]
$$$$TEST$$$$

^^^^TEST^^^^
[3,5,2,6]
[10,10,15,12]
"RLRL"
-------------------
[14]
$$$$TEST$$$$

^^^^TEST^^^^
[1,2,5,6]
[10,10,11,11]
"RLRL"
-------------------
[]
$$$$TEST$$$$

^^^^TEST^^^^
[4,37,23]
[50,15,49]
"RLR"
-------------------
[50,48]
$$$$TEST$$$$
'''

