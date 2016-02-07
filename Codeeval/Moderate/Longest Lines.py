import sys
sys.stdin = open(sys.argv[1], 'r')

n = int(raw_input())
strs = [line.strip() for line in sys.stdin]

print '\n'.join(
    sorted(strs, cmp=lambda x, y: cmp(len(x), len(y)), reverse=True)[:n])
