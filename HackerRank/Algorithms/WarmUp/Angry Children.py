n = input()
k = input()
candies = [input() for _ in range(0,n)]
candies.sort()
min_diff = min([candies[i + k - 1] - candies[i] for i in xrange(n - k + 1)])

print min_diff
