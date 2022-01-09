class Solution(object):
    def constructDistancedSequence(self, n):
        self.n = n
        tmp = [-1 for i in xrange(2 * n - 1)]
        visited = [False for i in xrange(0, n + 1)]
        return self.dfs(2 * n - 1, visited, tmp)

    def dfs(self, m, visited, buf):
        cur = 0
        while cur < m and buf[cur] != -1:
            cur += 1
        # print cur, buf
        if cur == m:
            return buf[:]

        res = []
        for i in xrange(self.n, 0, -1):
            if visited[i]:
                continue
            if i != 1:
                if cur + i >= m or buf[cur + i] != -1:
                    continue

            visited[i] = True

            buf[cur] = i
            if i != 1:
                buf[cur + i] = i

            res = self.dfs(m, visited, buf)

            buf[cur] = -1
            if i != 1:
                buf[cur + i] = -1
            visited[i] = False

            if res:
                break
        return res

