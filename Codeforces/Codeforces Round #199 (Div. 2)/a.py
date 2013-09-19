# coding = utf-8

n = int(raw_input())
l = map(int, raw_input().split())

c = [0 for i in xrange(10)]

for item in l:
    c[item] += 1

ans = True

vier, drei, sechs = 0, 0, 0

## COUNT 4
if ans:
    vier = c[4]
    c[1] -= vier
    c[2] -= vier

    if c[1] < 0 or c[2] < 0:
        ans = False

## COUNT 3
if ans:
    drei = c[3]
    c[1] -= drei
    c[6] -= drei

    if c[1] < 0 or c[6] < 0:
        ans = False

## COUNT 6
if ans:
    sechs = c[6]
    c[1] -= sechs
    c[2] -= sechs

    if c[1] < 0 or c[2] < 0:
        ans = False

if not ans or (vier + drei + sechs) * 3 != n:
    print -1
else:
    for i in xrange(vier):
        print '1 2 4'
    for i in xrange(drei):
        print '1 3 6'
    for i in xrange(sechs):
        print '1 2 6'
    


