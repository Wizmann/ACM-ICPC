# you can write to stdout for debugging purposes, e.g.
# print "this is a debug message"

def solution(A):
    s = sum(A)
    l = 0
    mini = 10 ** 10
    for num in A[:-1]:
        l += num
        s -= num
        mini = min(mini, abs(s - l))
    return mini
