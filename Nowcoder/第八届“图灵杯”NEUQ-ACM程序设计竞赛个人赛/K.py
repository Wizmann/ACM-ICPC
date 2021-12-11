s = raw_input()


def convert(c, x):
    if ord('a') <= ord(c) <= ord('z'):
        u = ord(c) + x
        if u > ord('z'):
            u = u - ord('z') + ord('A')
        return chr(u)
    else:
        u = ord(c) + x
        if u > ord('Z'):
            u = u - ord('Z') + ord('a')
        return chr(u)

chars = []
for c in s:
    if c.isalpha():
        chars.append(c)

nums = []
for c in s:
    if not c.isalpha():
        nums.append(int(c))

res = []
for c, num in zip(chars, nums):
    # print c, num
    c = convert(c, num)
    res.append(c)

ans = ''
for i in xrange(0, len(res), 4):
    ans += ''.join(res[i: i + 4][::-1])

import sys
sys.stdout.write(ans)


'''
^^^^TEST^^^
Zzc6Ltw2OD4yR640263W7G8G30HW9C71
-------
RgCgJQwxJfYCDeQG
$$$TEST$$$
'''

