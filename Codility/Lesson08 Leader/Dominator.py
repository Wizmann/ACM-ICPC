# you can write to stdout for debugging purposes, e.g.
# print "this is a debug message"

INF = 10 ** 10

def solution(A):
    cur, cnt, idx = -INF, -1, -1
    for i, item in enumerate(A):
        if cur != item:
            cnt -= 1
        else:
            cnt += 1
        if cnt <= 0:
            cur, cnt, idx = item, 1, i
    return idx if A.count(cur) >= len(A) / 2 + 1 else -1
