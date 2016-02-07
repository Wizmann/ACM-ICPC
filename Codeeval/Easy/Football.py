import sys
#sys.stdin = open(sys.argv[1], 'r')
sys.stdin=open('input.txt')

for line in sys.stdin:
    d = {}
    for i, l in enumerate(line.split('|')):
        for team in map(int, l.split()):
            d[team] = d.get(team, [])
            d[team].append(i + 1)
    for key, l in sorted(d.items(), key=lambda x: x[0]):
        print "%d:%s;" % (key, ','.join(map(str, sorted(l)))),
    print ''

