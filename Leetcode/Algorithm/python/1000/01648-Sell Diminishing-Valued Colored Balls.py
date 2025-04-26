MOD = (10 ** 9) + 7
class Solution(object):
    def maxProfit(self, inventory, orders):
        l, r = 0, max(inventory)
        inventory.sort(reverse=True)
        while l <= r:
            m = (l + r) / 2
            v = self.check(inventory, orders, m)
            if v > 0:
                l = m + 1
            else:
                r = m - 1
        return self.calc(inventory, orders, r) % MOD
    
    def check(self, inventory, orders, m):
        count = 0
        for num in inventory:
            if num >= m:
                count += num - m + 1
            if count >= orders:
                return True
        return count >= orders

    def calc(self, inventory, orders, m):
        count = 0
        res = 0
        for num in inventory:
            if orders == count:
                break
            if num >= m + 1:
                c = min(orders - count, num - (m + 1) + 1)
                res += (num + num - c + 1) * c / 2
                count += c
        res += (orders - count) * m
        return res
