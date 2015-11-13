import math

T = int(raw_input())

for i in xrange(T):
    x = int(raw_input())
    
    a = math.log10(math.sqrt(2 * math.pi * x))
    b = math.log10(x / math.e) * x
    
    print int(a + b + 1)
