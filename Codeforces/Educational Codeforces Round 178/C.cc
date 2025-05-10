def solve(n, cards):
    if cards == 'AB':
        return True
    if cards == 'BA':
        return False
    if cards.count('B') == 1:
        return True
    a = cards.count('A')
    b = n - a

    aa = 0
    bb = 0
    for i in xrange(n - 1, -1, -1):
        if i == n - 1:
            if cards[n - 1] == 'A' and cards[0] == 'A':
                return True
        if cards[i] == 'A':
            aa += 1
            if i != n - 1 and bb == 0:
                return True
        else:
            bb += 1
    return False

T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())
    cards = raw_input().strip()

    if solve(n, cards):
        print 'Alice'
    else:
        print 'Bob'

'''
^^^^^TEST^^^
1
4
BABA
------------
Bob
$$$$TEST$$$


^^^^^TEST^^^^
8
2
AB
2
BA
4
ABAB
4
BABA
3
BAA
5
AAAAB
5
BAAAB
6
BBBAAA
------------------
Alice
Bob
Bob
Bob
Alice
Alice
Bob
Alice
$$$$$TEST$$$$
'''


