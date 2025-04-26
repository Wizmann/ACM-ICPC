def f1(ns):
    return map(lambda x: x ^ 1, ns)

def f2(ns):
    n = len(ns)
    for i in xrange(1, n, 2):
        ns[i] ^= 1
    return ns

def f3(ns):
    n = len(ns)
    for i in xrange(0, n, 2):
        ns[i] ^= 1
    return ns

def f4(ns):
    n = len(ns)
    for i in xrange(1, n + 1, 3):
        ns[i - 1] ^= 1
    return ns

fs = [f1, f2, f3, f4]

class Solution(object):
    def flipLights(self, n, m):
        st = set()
        for i in xrange(1 << 4):
            actions = []
            for j in xrange(4):
                actions.append(1 if i & (1 << j) else 0)
            if sum(actions) > m:
                continue
            if (m - sum(actions)) % 2 != 0:
                continue
            ns = [1] * n
            
            for i in xrange(4):
                if actions[i]:
                    ns = fs[i](ns)
            #print actions, ns
            st.add(tuple(ns))
        return len(st)
            
            
