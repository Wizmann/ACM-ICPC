vowels = 'AEIOUY'

s = raw_input()
s = [0] + [i + 1 for i, c in enumerate(s) if c in vowels] + [len(s) + 1]

ans = 0
for i in xrange(1, len(s)):
    ans = max(ans, s[i] - s[i - 1])

print ans
