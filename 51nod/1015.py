def do_detect(n):
    l = len(str(n))
    m = sum(map(lambda x: x ** l, map(int, str(n))))
    #print n, m
    return n == m

n = int(raw_input())

while True:
    if do_detect(n):
        print n
        break
    n += 1
