n = int(raw_input())

m = n
res = 1

while n:
    if n & 1:
        res *= m
    m *= m
    
    res %= 10
    m %= 10
    n /= 2
print res
