class Solution(object):
    def shortestSequence(self, rolls, k):
        n = len(rolls)
        st = set()
        cnt = 0
        for num in rolls:
            st.add(num)
            if len(st) == k:
                cnt += 1
                st = set()
        return cnt + 1


'''
^^^^TEST^^^^^
[4,2,1,2,3,3,2,4,1]
4
------
3
$$$TEST$$$$
'''
