# https://leetcode.com/problems/apply-discount-every-n-orders/

from typing import *

class Cashier(object):
    def __init__(self, n: int, discount: int, products: List[int], prices: List[int]):
        self.n = n
        self.discount = discount
        self.products = products
        self.prices = prices
        self.pp = dict(zip(self.products, self.prices))
        self.counter = 0

    def getBill(self, product: List[int], amount: List[int]) -> float:
        self.counter += 1
        discount = self.discount if self.counter % self.n == 0 else 0

        tot = 0
        for (p, c) in zip(product, amount):
            tot += self.pp[p] * c
        return tot - 1.0 * (discount * tot) / 100

C = Cashier(2, 1, [1, 2], [100, 200])
assert C.getBill([1], [100]) == 100 * 100
assert C.getBill([1, 2], [1, 1]) == (100 + 200) * 0.99
assert C.getBill([1], [100]) == 100 * 100

