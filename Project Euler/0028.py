N = 1001

ans = 0

ans += sum(map(lambda x: x ** 2, range(1, N + 1, 2)))
ans += 3 * sum(map(lambda x: x ** 2 - (x - 1) * 2, range(3, N + 1, 2)))
print ans
