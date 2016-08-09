#coding=utf-8

def judge(func, x):
    now = 0
    step = x
    while step:
        half = step / 2
        mid = now + half
        if func(mid) >= x:
            step = half
        else:
            now = mid + 1
            step = step - half - 1
    return func(now) == x

tri = lambda x: x * (x + 1) / 2
pen = lambda x: x * (3 * x - 1) / 2
hxa = lambda x: x * (2 * x - 1)

def test_judge():
    for i in xrange(1, 16):
        if i in [1, 3, 6, 10, 15]:
            assert(judge(tri, i) == True)
        else:
            assert(judge(tri, i) == False)

    for i in xrange(1, 36):
        if i in [1, 5, 12, 22, 35]:
            assert(judge(pen, i) == True)
        else:
            assert(judge(pen, i) == False)

    for i in xrange(1, 46):
        if i in [1, 6, 15, 28, 45]:
            assert(judge(hxa, i) == True)
        else:
            assert(judge(hxa, i) == False)

if __name__ == '__main__':
    test_judge()

    i = 165
    while True:
        i += 1
        v = pen(i)
        if judge(tri, v) and \
           judge(pen, v) and \
           judge(hxa, v):
            break
    print pen(i)
