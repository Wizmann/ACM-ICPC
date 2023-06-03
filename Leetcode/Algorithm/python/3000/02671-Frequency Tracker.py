from collections import defaultdict

class FrequencyTracker(object):

    def __init__(self):
        self.d = defaultdict(int)
        self.c = defaultdict(set)

    def change(self, number, delta):
        pre = self.d[number]
        nxt = pre + delta
        self.d[number] = nxt
        if pre == 0:
            self.c[nxt].add(number)
        else:
            self.c[pre].remove(number)
            self.c[nxt].add(number)

    def add(self, number):
        self.change(number, +1)
        

    def deleteOne(self, number):
        if self.d[number] == 0:
            return
        self.change(number, -1)
        

    def hasFrequency(self, frequency):
        return self.c[frequency]
        


# Your FrequencyTracker object will be instantiated and called as such:
# obj = FrequencyTracker()
# obj.add(number)
# obj.deleteOne(number)
# param_3 = obj.hasFrequency(frequency)
