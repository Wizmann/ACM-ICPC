def common_prefix(items):
    i = 0
    while True:
        s = set()
        for item in items:
            if i >= len(item):
                return i
            s.add(item[i])
        if len(s) > 1:
            return i
        else:
            i += 1

assert common_prefix(['0', '01', '001']) == 1
assert common_prefix(['01', '011', '01011']) == 2
assert common_prefix(['0', '01', '101']) == 0


n = int(raw_input())

items = map(int, raw_input().split())
items_str = map(lambda x: '{:b}'.format(x), items)
lens = []

u = common_prefix(items_str)
step = 0
for item in items_str:
    #print item
    for i in xrange(u, len(item)):
        if item[i] != '0':
            step += len(item) - i
            lens.append(i)
            break
    else:
        lens.append(len(item))
#print step, lens
lens.sort()
step += sum(map(lambda x: abs(x - lens[n / 2]), lens))
print step
