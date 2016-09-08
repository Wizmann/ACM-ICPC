import math

la = float(raw_input())
k = int(raw_input())

P = (math.e ** -la) * (la ** k) / math.factorial(k)

print '%.3f' % P
