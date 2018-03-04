class PhoneDirectory(object):

    def __init__(self, maxNumbers):
        self.recycled = []
        self.auto_increment = 0
        self.used = set()
        self.maxi = maxNumbers

    def get(self):
        if self.recycled:
            number = self.recycled.pop()
        else:
            number = self.auto_increment
            self.auto_increment += 1
        if number >= self.maxi:
            return -1
        self.used.add(number)
        return number

    def check(self, number):
        return number not in self.used

    def release(self, number):
        if number in self.used:
            self.recycled.append(number)
            self.used.remove(number)        


# Your PhoneDirectory object will be instantiated and called as such:
# obj = PhoneDirectory(maxNumbers)
# param_1 = obj.get()
# param_2 = obj.check(number)
# obj.release(number)
