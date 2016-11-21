a, b = map(int, raw_input().split())
for i in xrange(1, 11):
    x1 = a * i - b
    x2 = a * i
    
    if (x1 >= 0 and x1 % 10 == 0) or (x2 >= 0 and x2 % 10 == 0):
        print i
        break
