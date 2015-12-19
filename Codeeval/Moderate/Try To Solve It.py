import sys
test_cases = open(sys.argv[1], 'r')

a, b = map(lambda x: x.lower().replace(' ', '').replace('|', ''),
    [
        'A | B | C | D | E | F | G | H | I | J | K | L | M',
        'U | V | W | X | Y | Z | N | O | P | Q | R | S | T'
    ])
    
d = dict(zip(a, b) + zip(b, a))

for test in test_cases:
    print ''.join(map(lambda x: d[x], test.strip()))

test_cases.close()
