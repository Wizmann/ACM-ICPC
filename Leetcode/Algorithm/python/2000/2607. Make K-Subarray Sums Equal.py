class Solution(object):
    def makeSubKSumEqual(self, arr, k):
        n = len(arr)
        visited = [False for i in xrange(n)]
        res = 0
        for i in xrange(n):
            if visited[i]: 
                continue
            j = i
            cur = []
            while not visited[j]:
                visited[j] = True
                cur.append(arr[j])
                j = (j + k) % n
            cur.sort()
            mid = cur[len(cur) / 2]
            for num in cur:
                res += abs(num - mid)
        return res
