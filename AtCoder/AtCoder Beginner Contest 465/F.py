# py3

"""
^^^^test^^^^
5
000000 1
314159 2
161803 10
169231 5
384400 20
4
150001 269944
302010 396939
000000 999999
999000 000444
---
15
0
38
0
$$$$test$$$$

^^^^test^^^^
8
778722 12744734
488742 359266786
955942 335004463
454854 331175626
934246 179761526
927777 657312747
652568 109900930
753279 405123850
8
201000 785589
202325 955898
310401 875947
044023 988999
111230 567897
133241 577989
101033 999499
453013 796988
---
515024780
109900930
0
331175626
331175626
331175626
584885376
331175626
$$$$test$$$$
"""

import sys


def main():
    n = int(input())

    # Index digits in base 10: d0 + 10*d1 + ... + 10^5*d5.
    size = 10 ** 6
    a = [0] * size

    for _ in range(n):
        s, v = input().split()
        idx = 0
        for c in s:
            idx = idx * 10 + (ord(c) - 48)
        a[idx] = int(v)

    # Inclusive 6-dimensional prefix sums.
    stride = 1
    for _ in range(6):
        block = stride * 10
        for start in range(0, size, block):
            end = start + block
            for i in range(start + stride, end):
                a[i] += a[i - stride]
        stride *= 10

    weights = (100000, 10000, 1000, 100, 10, 1)

    q = int(input())
    out = []

    for _ in range(q):
        x, y = input().split()
        lo = [ord(c) - 48 for c in x]
        hi = [ord(c) - 48 for c in y]

        if any(lo[d] > hi[d] for d in range(6)):
            out.append("0")
            continue

        base = sum(hi[d] * weights[d] for d in range(6))

        # Build the 64 corner offsets, grouped by inclusion-exclusion sign.
        even = [0]
        odd = []
        for d in range(6):
            if lo[d]:
                delta = (hi[d] - lo[d] + 1) * weights[d]
                old_even = even
                old_odd = odd
                even = old_even + [v + delta for v in old_odd]
                odd = old_odd + [v + delta for v in old_even]

        ans = sum(a[base - offset] for offset in even)
        ans -= sum(a[base - offset] for offset in odd)
        out.append(str(ans))

    print("\n".join(out))


if __name__ == "__main__":
    main()
