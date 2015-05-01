class Solution:
    # @param {integer} n
    # @return {boolean}
    def isHappy(self, n):
        st = set([1])
        while n not in st:
            st.add(n)
            n = sum(
                map(lambda x: x ** 2,
                map(int,
                str(n))))
        return n == 1
