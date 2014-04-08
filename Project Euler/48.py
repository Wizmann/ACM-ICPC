print reduce(lambda a, b: (a + b) % 10000000000, map(lambda x: pow(x, x, 10000000000), range(1, 1001)))
