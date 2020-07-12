def solve(a, m):
    st = set()
    while True:
        if a == 0:
            return 'Yes'
        if a in st:
            return 'No'
        st.add(a)
        a = (a + a) % m
    assert False

assert solve(1, 5) == 'No'
assert solve(3, 6) == 'Yes'
assert solve(1, 1) == 'Yes'

if __name__ == '__main__':
    a, m = map(int, raw_input().split())
    print solve(a, m)
