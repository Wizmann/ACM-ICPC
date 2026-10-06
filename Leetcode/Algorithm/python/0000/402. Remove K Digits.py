def solve(num, k):
    st = []
    num = map(int, str(num))
    for digit in num:
        while st and k and digit < st[-1]:
            st.pop()
            k -= 1
        st.append(digit)
    while k:
        st.pop()
        k -= 1

    if not st:
        return 0
    return int(''.join(map(str, st)))

assert solve(1432219, 3) == 1219
assert solve(10200, 1) == 200
assert solve(10, 2) == 0
assert solve(1230, 3) == 0

class Solution(object):
    def removeKdigits(self, num, k):
        return str(solve(num, k))
