T = int(raw_input())

for case_ in xrange(T):
    try:
        m = int(raw_input())
        n = int(raw_input())
        ns = map(int, raw_input().split())

        d = {}
        for i, num in enumerate(ns):
            if num not in d:
                d[num] = []
            d[num].append(i)

        for i, num in enumerate(ns):
            x, y = num, m - num
            if y not in d:
                continue
            if x == y:
                for idx in d[x]:
                    if idx != i:
                        print min(i, idx) + 1, max(i, idx) + 1
                        raise Exception("super break")
            else:
                idx = d[y][0]
                print min(i, idx) + 1, max(i, idx) + 1
                raise Exception("super break")
        else:
            print 'fuck me'
    except:
        pass
        # import traceback
        # traceback.print_exc()
        
