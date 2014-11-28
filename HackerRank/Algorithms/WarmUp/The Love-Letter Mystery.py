n = int(raw_input())

for i in xrange(n):
    num = raw_input()
    left, right = num[:len(num) / 2], num[(len(num) + 1) / 2:][::-1]
    print sum(map(lambda (x, y): abs(ord(x) - ord(y)), zip(left, right)))
