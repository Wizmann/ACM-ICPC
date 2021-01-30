#coding=utf-8
INF = 10 ** 10

def solve(n):
    st = set()
    for i in xrange(1, INF):
        if i * i > n:
            break
        if n % i == 0:
            ns = [i, n / i]
            for num in ns:
                if num % 2 == 1:
                    st.add(num)
                if (n / num) % 2 != 0:
                    st.add(num * 2)

    return len(st)

assert solve(1) == 2
assert solve(12) == 4
#assert solve(963761198400) == 1920

n = int(raw_input())
print solve(n)

'''
^^^TEST^^^
1
---
2
$$$TEST$$$

^^^TEST^^^
12
---
4
$$$TEST$$$

^^^TEST^^^
963761198400
---
1920
$$$TEST$$$
'''
