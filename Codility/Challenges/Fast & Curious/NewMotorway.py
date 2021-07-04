# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

MOD = (10 ** 9) + 7
INF = 10 ** 100

def solution(A):
    n = len(A)
    pre = A[:]
    for i in range(1, n):
        pre[i] += pre[i - 1]
    
    def presum(a, b):
        if a > b:
            return 0
        aa = 0
        if a - 1 >= 0:
            aa = pre[a - 1]
        return pre[b] - aa
    
    mini = INF
    for i in range(n - 1):
        left_cnt = i
        left_sum = presum(0, i - 1)
        right_cnt = n - i - 1
        right_sum = presum(i + 1, n - 1)

        cur = A[i] * left_cnt - left_sum + \
              A[-1] * right_cnt - right_sum
        # print left_cnt, left_sum, right_cnt, right_sum
        # print cur
        mini = min(mini, cur)
    
    return mini % MOD

assert solution([1, 5, 9, 12]) == 7
