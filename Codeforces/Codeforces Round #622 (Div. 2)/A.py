# http://codeforces.com/contest/1313/problem/A

def do_solve(cnt, u):
    if u & 1:
        return False
    for i in range(1, 8):
        if not (u & (1 << i)):
            continue
        for j in range(3):
            if not (i & (1 << j)):
                continue
            if cnt[j]:
                cnt[j] -= 1
            else:
                return False
    return True
 
def solve(a, b, c):
    cnt = [a, b, c]
    res = 0
    for i in range(1, 1 << 8):
        b = '{:b}'.format(i).count('1')
        if b <= res:
            continue
        if do_solve(cnt[:], i):
            res = max(res, '{:b}'.format(i).count('1'))
    return res
 
assert do_solve([1, 2, 1], 7) == False
assert do_solve([1, 2, 1], 2) == True
assert do_solve([1, 2, 1], (1 << 8) - 1) == False
assert solve(1, 2, 1) == 3
assert solve(0, 0, 0) == 0
assert solve(9, 1, 7) == 4
assert solve(2, 2, 3) == 5
 
T = int(input())
for case_ in range(T):
    a, b, c = map(int, input().split())
    print(solve(a, b, c))
