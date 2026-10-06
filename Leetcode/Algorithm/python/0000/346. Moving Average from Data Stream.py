class MovingAverage(object):

    def __init__(self, size):
        self.data = []
        self.size = size
        self.sum = 0
        

    def next(self, val):
        self.data.append(val)
        self.sum += val
        if len(self.data) > self.size:
            self.sum -= self.data[-self.size - 1]
            return 1.0 * self.sum / self.size
        else:
            return 1.0 * self.sum / len(self.data)
        


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)
