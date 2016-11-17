def persistence(n):
    step = 0
    while n >= 10:
        n = reduce(lambda x, y: x * y, map(int, str(n)))
        step += 1
    return step
