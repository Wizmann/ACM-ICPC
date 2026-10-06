INF = 10 ** 10

class Solution(object):
    def memLeak(self, memory1, memory2):
        flag = True
        for i in xrange(1, INF):
            if memory1 >= memory2:
                if memory1 < i:
                    flag = False
                else:
                    memory1 -= i
            else:
                if memory2 < i:
                    flag = False
                else:
                    memory2 -= i
            if not flag:
                return [i, memory1, memory2]
        assert False
        return []
