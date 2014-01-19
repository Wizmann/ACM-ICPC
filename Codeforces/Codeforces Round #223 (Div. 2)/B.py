SIZE = 5120

n = int(raw_input())
cards = map(int, raw_input().split())

cnt = [0 for i in xrange(SIZE)]

maxi = max(cards)
for item in cards:
    cnt[item] += 1

left = []
right = []
for i in xrange(maxi):
    if cnt[i] == 1:
        left.append(i)
    elif cnt[i] > 1:
        left.append(i)
        right.append(i)
left.sort()
right.sort(reverse=True)

ans = left + [maxi] + right
print len(ans)
print ' '.join(map(str, ans))
