

n, w = map(int, raw_input().split())
cheeses = []

for i in xrange(n):
    a, b = map(int, raw_input().split())
    cheeses.append((a, b))

cheeses.sort(reverse=True)

tot = 0
for (a, b) in cheeses:
    u = min(w, b)
    tot += u * a
    w -= u
    assert w >= 0
    if w == 0:
        break

print tot

'''
^^^TEST^^^
3 5
3 1
4 2
2 3
-----
15
$$$TEST$$$$

^^^^^TEST^^^
4 100
6 2
1 5
3 9
8 7
------
100
$$$TEST$$$

^^^TEST^^^
10 3141
314944731 649
140276783 228
578012421 809
878510647 519
925326537 943
337666726 611
879137070 306
87808915 39
756059990 244
228622672 291
------
2357689932073
$$$TEST$$$

'''




