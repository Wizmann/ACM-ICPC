INF = 10 ** 10

class Solution(object):
    def earliestAndLatest(self, n, firstPlayer, secondPlayer):
        self.d = set()
        status = 0
        status |= 1 << (firstPlayer - 1)
        status |= 1 << (secondPlayer - 1)
        self.mini = INF
        self.maxi = -INF
        self.dfs(n, status, 0)
        return [self.mini, self.maxi]
    
    def dfs(self, n, status, step):
        step += 1
        if (n, status) in self.d:
            return
        self.d.add((n, status))
        binary = map(int, ('{:0%db}' % n).format(status))[::-1]
        # print n, binary, step
        
        for i in xrange(n / 2):
            if binary[i] == 1 and binary[n - i - 1] == 1:
                self.mini = min(self.mini, step)
                self.maxi = max(self.maxi, step) 
                return

        for i in xrange(1 << (n / 2)):
            bits = []
            for j in xrange(n / 2):
                if binary[j]:
                    bits.append(j)
                elif binary[n - j - 1]:
                    bits.append(n - j - 1)
                else:
                    if i & (1 << j):
                        bits.append(j)
                    else:
                        bits.append(n - j - 1)
            if n % 2 == 1:
                bits.append(n / 2)
            bits.sort()
            num = 0
            for bit in bits:
                num = num * 2 + binary[bit]
            # print '>>', n, bits, num
            self.dfs((n + 1) / 2, num, step)
