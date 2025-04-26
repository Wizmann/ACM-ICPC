class ATM(object):

    def __init__(self):
        self.items = {
            20: 0,
            50: 0,
            100: 0,
            200: 0,
            500: 0
        }

    def deposit(self, banknotesCount):
        items = zip([20, 50, 100, 200, 500], banknotesCount)
        for (key, value) in items:
            self.items[key] += value
        

    def withdraw(self, amount):
        rem = amount
        for key in [20, 50, 100, 200, 500][::-1]:
            if rem == 0:
                break
            u = min(self.items[key], rem / key)
            rem -= key * u
        if rem:
            return [-1]
        rem = amount
        res = []
        for key in [20, 50, 100, 200, 500][::-1]:
            u = min(self.items[key], rem / key)
            self.items[key] -= u
            res.append(u)
            rem -= key * u
        return res[::-1]
            
        


# Your ATM object will be instantiated and called as such:
# obj = ATM()
# obj.deposit(banknotesCount)
# param_2 = obj.withdraw(amount)
