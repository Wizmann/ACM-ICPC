import math

v = 600851475143

up = int(math.sqrt(v)) + 1

f = []

for i in xrange(2, up):
    if v % i == 0:
        f.append(i)
    while v % i == 0:
        v /= i

print max(f)
        
