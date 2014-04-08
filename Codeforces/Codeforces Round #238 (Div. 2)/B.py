# Result: 6124529    Mar 23, 2014 3:10:42 PM    Wizmann  B - Domino Effect   Python 2   Accepted    61 ms   104 KB
n = int(raw_input())
   
def find(card, direction, niddle):
    res = [-1 for i in xrange(n)]
    pre = -1
    for i in range(n)[::direction]:
        if card[i] == '.':
            res[i] = -1 if pre == -1 else abs(i - pre)
        elif card[i] == niddle:
            pre = i
        else:
            pre = -1
    return res
 
def findright(card):
    return find(card, 1, 'R')

def findleft(car):
    return find(card, -1, 'L')


card = raw_input()
left = findleft(card)
right = findright(card)

ans = 0
for i in xrange(n):
    if card[i] == '.' and left[i] == right[i]:
            ans += 1
print ans
