primes = [2, 3, 5, 7, 11, 13, 17, 19]

ans = 1
for item in primes:
    a = item
    while a <= 20:
        a *= item
    
    ans *= a / item

print ans
