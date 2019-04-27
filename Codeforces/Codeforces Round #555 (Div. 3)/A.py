def f(n):
    n = list(str(n + 1))
    while n[-1] == '0':
        n.pop()
    return int(''.join(n))

assert f(599) == 6
assert f(7) == 8
assert f(9) == 1

n = int(raw_input())

st = set()

while n not in st:
    st.add(n)
    n = f(n)

print len(st)
