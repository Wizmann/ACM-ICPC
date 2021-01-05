class Solution(object):
    def findLengthOfShortestSubarray(self, arr):
        n = len(arr)
        st = []
        for i in xrange(n - 1, -1, -1):
            if i + 1 >= n or arr[i] <= arr[i + 1]:
                st.append(i)
            elif arr[i] > arr[i + 1]:
                break
        res = len(st)
        u = 0
        # print st
        for i in xrange(n):
            if i - 1 < 0 or arr[i - 1] <= arr[i]:
                u += 1
                while st and st[-1] <= i:
                    st.pop()
                while st and arr[st[-1]] < arr[i]:
                    st.pop()
                res = max(res, u + len(st))
            elif arr[i - 1] > arr[i]:
                break
        return n - res
        
            
