class Solution(object):
    def longestMountain(self, A):
        n = len(A)
        l, r, b = 0, 0, False
        ans = 0
        while r < n:
            if l == r or (b == False and A[r] > A[r - 1]) or (b == True and A[r] < A[r - 1]):
                r += 1
                #print l, r
                if b == True and r - l >= 3:
                    ans = max(ans, r - l)
            elif r - 1 != l and b == False and A[r] < A[r - 1]:
                r += 1
                b = True
                #print l, r
                if r - l >= 3:
                    ans = max(ans, r - l)
            else:
                l = r - 1
                if A[l] >= A[r]:
                    l += 1
                r += 1
                b = False
        return ans
                
