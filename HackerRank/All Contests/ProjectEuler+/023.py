def get_div(x):
    i = 1
    st = set()
    while i * i <= x:
        if x % i == 0:
            st.add(i)
            st.add(x / i)
        i += 1
    st.remove(x)
    return st

xs = set()
for i in xrange(1, 10 ** 5 + 1):
    if sum(get_div(i)) > i:
        xs.add(i)

T = int(raw_input())
for i in xrange(T):
    y = int(raw_input())
    
    for x in xs:
        if y - x in xs:
            print 'YES'
            break
    else:
        print 'NO'
        
