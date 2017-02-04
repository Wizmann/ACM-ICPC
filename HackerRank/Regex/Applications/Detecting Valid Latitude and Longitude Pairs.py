import re

def solve(s):
    valid_float = '[+-]?(?:[1-9]\d*|0)(?:.\d+)?'
    g = re.search("^\(({0}),\ ({0})\)$".format(valid_float), s)

    if not g or len(g.groups()) != 2:
        return False
    (x, y) = g.groups()
    return -90 <= float(x) <= 90 and -180 <= float(y) <= 180

assert solve('(-6, -172)')
assert solve('(75, 180)')
assert solve('(+90.0, -147.45)')
assert solve('(77.11112223331, 149.99999999)')
assert solve('(+90, +180)')
assert solve('(90, 180)')
assert solve('(-90.00000, -180.0000)')
assert solve('(75, 280)') == False
assert solve('(+190.0, -147.45)') == False
assert solve('(77.11112223331, 249.99999999)') == False
assert solve('(+90, +180.2)') == False
assert solve('(90., 180.)') == False
assert solve('(-090.00000, -180.0000)') == False

if __name__ == '__main__':
    n = int(raw_input())
    for i in xrange(n):
        s = raw_input()
        print 'Valid' if solve(s) else 'Invalid'
