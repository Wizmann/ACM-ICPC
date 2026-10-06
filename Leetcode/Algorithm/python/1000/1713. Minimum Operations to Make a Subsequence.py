INF = 10 ** 10

class Solution(object):
    def minOperations(self, target, arr):
        pos = {}
        for i, num in enumerate(target):
            pos[num] = i
        n = len(target)
        arr = map(lambda x: pos.get(x, INF), arr)
        arr.append(INF)
        
        res = self.lis(arr)
        return n - (res - 1)
    
    def lis(self, arr):
        st = []
        for num in arr:
            if not st or st[-1] < num:
                st.append(num)
            else:
                l, r = 0, len(st) - 1
                while l <= r:
                    m = (l + r) / 2
                    if st[m] >= num:
                        r = m - 1
                    else:
                        l = m + 1
                st[l] = num
            
        return len(st)
