(h, n) = map(int, raw_input().split())
ns = map(int, raw_input().split())
 
if h > sum(ns):
    print 'No'
else:
    print 'Yes'
