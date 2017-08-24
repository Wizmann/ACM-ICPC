n = int(raw_input())
ns = sorted(map(int, raw_input().split()))

a, b = ns[:n], ns[n:]

print 'YES' if max(a) < min(b) else 'NO'
