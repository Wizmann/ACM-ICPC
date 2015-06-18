n = int(raw_input())
fishes = []

for i in xrange(n):
    (a, b) = map(int, raw_input().split())
    fishes.append({'size': a, 'dir': b})
    
cnt = 0
st = []

for fish in fishes:
    if fish['dir'] == 0:
        while st and st[-1] < fish['size']:
            st.pop()
        if not st:
            cnt += 1
    else:
        st.append(fish['size'])
        
print cnt + len(st)
