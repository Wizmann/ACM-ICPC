class Solution(object):
    def asteroidCollision(self, asteroids):
        res, st = [], []
        for item in asteroids:
            if item > 0:
                st.append(item)
                continue
            item = abs(item)
            while st:
                if st[-1] > item:
                    item = -1
                    break
                elif st[-1] == item:
                    item = -1
                    st.pop()
                    break
                else:
                    st.pop()
            if item == -1:
                continue
            res.append(-item)
        return res + st
