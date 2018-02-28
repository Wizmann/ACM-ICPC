from collections import Counter

s = raw_input()

cnt = 0
for key, value in Counter(s).items():
    if value % 2:
        cnt += 1

print 'YES' if cnt <= 1 else 'NO'
