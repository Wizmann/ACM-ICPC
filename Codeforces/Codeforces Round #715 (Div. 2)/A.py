T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())
    ns = map(int, raw_input().split())

    ns.sort(key=lambda x: x % 2)
    print ' '.join(map(str, ns))


'''

^^^TEST^^^
4
3
1 1 2
3
1 1 1
8
10 9 13 15 3 16 9 13
2
18 9
----
1 1 2 
1 1 1 
13 9 13 15 3 9 16 10 
9 18 
$$$TEST$$$

'''

