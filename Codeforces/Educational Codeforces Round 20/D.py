INF = 10 ** 10
def judge(words, m):
    res = 0
    l = 0
    for i, word in enumerate(words):
        for j, s in enumerate(word):
            ll = len(s) + \
                (0 if i == len(words) - 1 and j == len(word) - 1 else 1)
            if ll > m:
                return INF
            if l + ll > m:
                res += 1
                l = ll
            else:
                l += ll
    if l:
        res += 1
    return res

#assert judge('garage for sa-le'.split(), 7) == 3
#assert judge('Edu-ca-tion-al Ro-unds are so fun'.split(), 10) == 4

k = int(raw_input())
words = raw_input().split()

for i, word in enumerate(words):
    words[i] = word.split('-')

l, r = 0, 10 ** 6
while l <= r:
    m = (l + r) >> 1
    #print m, words, judge(words, m)
    if judge(words, m) > k:
        l = m + 1
    else:
        r = m - 1
print l
