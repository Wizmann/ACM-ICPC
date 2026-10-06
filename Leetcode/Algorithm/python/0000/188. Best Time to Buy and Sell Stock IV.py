class Solution(object):
    def maxProfit(self, k, prices):
        st = []
        n = len(prices)
        profits = []

        p, q = 0, 0
        while p < n:
            while p + 1 < n and prices[p] >= prices[p + 1]:
                p += 1
            q = p + 1
            while q + 1 < n and prices[q] <= prices[q + 1]:
                q += 1

            if p >= n or q >= n:
                break

            while st and prices[st[-1][0]] >= prices[p]:
                l, r = st.pop()
                profits.append(prices[r] - prices[l])

            while st and prices[st[-1][1]] <= prices[q]:
                l, r = st.pop()
                profits.append(prices[r] - prices[p])
                p = l

            st.append((p, q))
            p = q + 1

        while st:
            l, r = st.pop()
            profits.append(prices[r] - prices[l])

        return sum(sorted(profits, reverse=True)[:k])
