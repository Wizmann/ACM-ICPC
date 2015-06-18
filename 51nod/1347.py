import sys

def solve(line):
    n = len(line)
    if n % 2:
        return False
    return line[:n/2] == line[n/2:]
for line in sys.stdin:
    if solve(line.strip()):
        print 'YES'
    else:
        print 'NO'
