n = int(raw_input())

ps = []
for i in xrange(n):
    name, age = raw_input().split()
    age = int(age)
    ps.append((name, age))

mini = min(map(lambda x: x[1], ps))

idx = 0
for i in xrange(n):
    if ps[i][1] == mini:
        idx = i
        break

for i in xrange(n):
    print ps[(i + idx) % n][0]

'''
^^^TEST^^^^
5
alice 31
bob 41
carol 5
dave 92
ellen 65
-------------
carol
dave
ellen
alice
bob
$$$$TEST$$$$
'''

