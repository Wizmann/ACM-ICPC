#python3

n = int(input())
As = list(map(int, input().split()))

m = int(input())
Bs = list(map(int, input().split()))

l = int(input())
Cs = list(map(int, input().split()))

st = set()

for a in As:
    for b in Bs:
        for c in Cs:
            # print("A: %d, B: %d, C: %d" % (a, b, c))
            st.add(a + b + c)

Q = int(input())
Xs = map(int, input().split())

# print(st)

for x in Xs:
    if x in st:
        print('Yes')
    else:
        print('No')

'''
^^^^^^^^^^TEST^^^^
3
1 2 3
2
2 4
6
1 2 4 8 16 32
4
1 5 10 50
-------------
No
Yes
Yes
No
$$$$TEST$$$
'''


