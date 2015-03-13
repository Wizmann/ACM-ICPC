def get_next(word, l, kmp_next):
    kmp_next[0] = -1

    pre, suf = -1, 0

    while suf < l:
        if pre == -1 or word[pre] == word[suf]:
            pre += 1
            suf += 1
            kmp_next[suf] = pre
        else:
            pre = kmp_next[pre]

n = int(raw_input())
word = raw_input()
m = len(word)
kmp_next = [-1 for i in xrange(m + 1)]

get_next(word, m, kmp_next)

i = m
res = []
while i > 0:
    res.append(i)
    i = kmp_next[i]

res = res[::-1]
i = 0
j = 1
ans = 0

for num in res:
    while i < num:
        j *= n
        i += 1
    ans += j

print ans
