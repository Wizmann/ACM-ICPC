# https://leetcode.com/problems/design-a-stack-with-increment-operation/

class CustomStack:

    def __init__(self, maxSize: int):
        self.maxSize = maxSize
        self.st = []
        self.delta = [0 for i in range(maxSize)]

    def push(self, x: int) -> None:
        if len(self.st) >= self.maxSize:
            return
        self.st.append(x)
        n = len(self.st)
        # print("push", self.st, self.delta)
        self.delta[n - 1] = 0
        
    def pop(self) -> int:
        if not self.st:
            return -1
        n = len(self.st)
        res = self.st.pop() + self.delta[n - 1]
        # print("pop", self.st, self.delta)
        if n - 2 >= 0:
            self.delta[n - 2] += self.delta[n - 1]
        return res
        
    def increment(self, k: int, val: int) -> None:
        n = len(self.st)
        self.delta[min(n - 1, k - 1)] += val
        
# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)
