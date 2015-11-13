s = map(ord, raw_input())

d = {}
for item in s:
    d[item] = d.get(item, 0) + 1
    
st = []

for item in s:
    if item in st:
        pass
    elif not st:
        st.append(item)
    else:
        while st and st[-1] >= item and d[st[-1]] >= 1:
            st.pop()
        st.append(item)
    d[item] -= 1
    
print ''.join(map(chr, st))
