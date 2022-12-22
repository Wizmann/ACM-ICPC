
T = int(raw_input())
for case_ in xrange(T):
    n, x = map(int, raw_input().split())

    ns = range(n + 1)

    ns[n] = 1
    ns[1] = x

    if x != n:
        ns[x] = n
        # print ns

        i = x + 1
        cur = x
        while i <= n - 1:
            if n % i == 0 and i % cur == 0:
                ns[i], ns[cur] = ns[cur], ns[i]
                cur = i
            i += 1
 

    # print ns

    for i in xrange(1, n):
        if ns[i] % i != 0:
            print -1
            break
    else:
        print ' '.join(map(str, ns[1:]))

'''
^^^^TEST^^^
3
3 3
4 2
5 4
------------
3 2 1 
2 4 3 1 
-1
$$$$TEST$$$

^^^^TEST^^^
1
8 2
------------
2 4 3 8 5 6 7 1
$$$$TEST$$$

'''


