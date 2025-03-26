import sys
input = sys.stdin.readline
print = sys.stdout.write

n, m = map(int, input().split())

for _ in range(m):
    _ = input()

print(str(n - m) + '\n')
