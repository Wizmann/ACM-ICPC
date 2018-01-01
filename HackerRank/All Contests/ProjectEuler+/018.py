if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        n = int(raw_input())
        ns = []
        for i in xrange(n):
            ns.append(map(int, raw_input().split()))
            
        for i in xrange(1, n):
            for j in xrange(i + 1):
                ns[i][j] += max(0 if j - 1 < 0 else ns[i - 1][j - 1], 
                                0 if j == i    else ns[i - 1][j])
                
        print max(ns[n - 1])
