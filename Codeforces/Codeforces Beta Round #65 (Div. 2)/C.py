#python3

def solve(n, ns):
    i = 1
    st = set()
    while i * i <= n:
        if n % i == 0:
            st.add(i)
            st.add(n // i)
        i += 1

    for m in st:
        if m < 3:
            continue
        u = n // m
        for i in range(u):
            flag = True
            for j in range(m):
                p = i + j * u
                if ns[p] == 0:
                    flag = False
                    break
            if flag:
                return True
    return False

n = int(input())
ns = list(map(int, input().split()))

if solve(n, ns):
    print('YES')
else:
    print('NO')


