from collections import defaultdict, Counter
import heapq

class Solution(object):
    def earliestSecondToMarkIndices(self, nums, indices):
        nums = [0] + nums

        n = len(nums)
        fi = [-1 for i in xrange(n)]
        first = set()

        for i, num in enumerate(indices):
            if fi[num] == -1:
                fi[num] = i
                first.add(i)

        l, r = 1, len(indices)
        while l <= r:
            m = (l + r) / 2
            if self.check(nums, indices, first, m):
                r = m - 1
            else:
                l = m + 1
        res = l
        # print res
        if res > len(indices):
            return -1
        return res

    def check(self, nums, indices, first, pos):
        pq = []
        rem = 0
        tot = sum(nums) + len(nums) - 1

        for i in xrange(pos - 1, -1, -1):
            cur = indices[i]
            if (i not in first) or nums[cur] <= 1:
                rem += 1
                continue
            if rem == 0:
                if pq and pq[0] < nums[cur]:
                    tot += heapq.heappop(pq) + 1
                    rem += 2
            if rem > 0:
                heapq.heappush(pq, nums[cur])
                tot -= nums[cur] + 1
                rem -= 1
            else:
                rem += 1
            # print i, cur, tot, rem, pq
        # print pos, rem, tot
        return rem >= tot

assert Solution().earliestSecondToMarkIndices([2,2], [1,2,1,1,2,2,2]) == 4
assert Solution().earliestSecondToMarkIndices([2,0,0,0], [1, 2]) == -1
assert Solution().earliestSecondToMarkIndices([3,2,3], [1,3,2,2,2,2,3]) == 6
assert Solution().earliestSecondToMarkIndices([0,2], [1,1,2,2,1]) == 4
assert Solution().earliestSecondToMarkIndices([0,0,1,2], [1,2,1,2,1,2,1,2]) == 7
assert Solution().earliestSecondToMarkIndices([1,2,3], [1,2,3]) == -1
assert Solution().earliestSecondToMarkIndices([5,3,2,0,3,5], [4,3,6,5,6,5,3,6,4,1,2,3,6,1]) == 13

