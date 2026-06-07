from collections import Counter
c = Counter(raw_input())
print len(filter(lambda x: x[1] == 1, c.items()))
