import sys

d = {
    'A': 'A',
    'H': 'H',
    'I': 'I',
    'M': 'M',
    'O': 'O',
    'T': 'T',
    'U': 'U',
    'V': 'V',
    'W': 'W',
    'X': 'X',
    'Y': 'Y',
    
    'b': 'd',
    'd': 'b',
    'o': 'o',
    
    'p': 'q',
    'q': 'p',
    'v': 'v',
    'w': 'w',
    'x': 'x',
}

s = raw_input()
n = len(s)

r = ''.join(map(lambda x: d.get(x, '$'), s[::-1]))

print 'TAK' if s == r else 'NIE'
