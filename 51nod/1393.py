ns = map(lambda x: x if x else -1,
        map(int, 
            list(raw_input())
        )
    )

pre = {0: -1}
ans = 0

s = 0
for i, v in enumerate(ns):
    s += v
    if s in pre:
        ans = max(ans, i - pre[s])
    else:
        pre[s] = i
        
print ans
