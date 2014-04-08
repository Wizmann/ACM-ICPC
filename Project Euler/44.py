#coding=utf-8

def judge(x):
    now = 0
    step = x
    while step:
        half = step / 2
        mid = now + half
        if (mid * (3 * mid - 1)) / 2 >= x:
            step = half
        else:
            now = mid + 1
            step = step - half - 1
    return (now * (3 * now - 1)) / 2 == x

def judge_abc(a, b):
    return judge(a) and judge(b)

def test_judge():
    ok = [1, 5, 12, 22, 35, 51, 70, 92, 117, 145]
    for i in xrange(1, 146):
        if i in ok:
            assert(judge(i) == True)
        else:
            assert(judge(i) == False)

def solve():
    pentagons = []
    i = 1
    flag = True
    while flag:
        if judge(i):
            for item in pentagons:
                if judge_abc(i - item, item + i):
                    print i, item
                    flag = False
                    break
            pentagons.append(i)
        i += 1

if __name__ == '__main__':
    test_judge()
    solve()


