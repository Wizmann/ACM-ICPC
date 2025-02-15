from collections import defaultdict

T = int(raw_input())

for case_ in xrange(T):
    (n, m) = map(int, raw_input().split())

    players = []
    for i in xrange(n):
        cards = sorted(map(int, raw_input().split()))
        players.append(cards)
    players = sorted(list(enumerate(players)), key=lambda x: x[1])

    pre = -1
    flag = True
    for i in xrange(m):
        if not flag:
            break
        for j in xrange(n):
            cur = players[j][1][i]
            if cur > pre:
                pre = cur
            else:
                flag = False
                break
    if flag:
        for i in xrange(n):
            print players[i][0] + 1,
        print ''
    else:
        print '-1'



'''
^^^^TEST^^^^^
4
2 3
0 4 2
1 5 3
1 1
0
2 2
1 2
0 3
4 1
1
2
0
3
------------
1 2
1
-1
3 1 2 4
$$$$$$$TEST$$$$
'''

 
