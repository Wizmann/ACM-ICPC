PRIME = 239

MOD = 0xdeadbeafcafebabe

class Solution(object):
    def countDistinct(self, nums, k, div):
        n = len(nums)
        p, q = 0, 0
        cnt = 0
        st = set()
        while True:
            while q < n and cnt <= k:
                if nums[q] % div == 0:
                    cnt += 1
                q += 1
            h = 0
            # print p, q, cnt
            for i in xrange(p, q if cnt <= k else q - 1):
                h = (h * PRIME + nums[i]) % MOD
                st.add(h)
            if nums[p] % div == 0:
                cnt -= 1
            p += 1
            if p >= n:
                break
        return len(st)
        
