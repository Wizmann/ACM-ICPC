'''$$$
[Description]
There are N workers.  The i-th worker has a quality[i] and a minimum wage expectation wage[i].

Now we want to hire exactly K workers to form a paid group.  When hiring a group of K workers, we must pay them according to the following rules:

* Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
* Every worker in the paid group must be paid at least their minimum wage expectation.

Return the least amount of money needed to form a paid group satisfying the above conditions.

[Tags]
greedy, heap

[Difficulty]
3.5

[Url]
https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/
$$$'''

import heapq

INF = 10 ** 10

class Solution(object):
    def mincostToHireWorkers(self, quality, wage, K):
        n = len(quality)
        ns = []
        pq = []
        for i in xrange(n):
            q, w = quality[i], wage[i]
            ns.append((1.0 * w / q, q))
        ns.sort()
        res = INF
        for (p, q) in ns:
            heapq.heappush(pq, -q)
            if len(pq) > K:
                heapq.heappop(pq)
            if len(pq) == K:
                res = min(res, -p * sum(pq))    
        return res
