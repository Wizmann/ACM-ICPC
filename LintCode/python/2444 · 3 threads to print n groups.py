# you can import any package that you need here
# -- write your code here -- 

from threading import Condition, Lock

class Solution:
    def __init__(self, n):
        self.n = n * 5
        self.lock = Lock()
        self.cond = Condition(self.lock)
        self.i = 1

    def first(self, print_first):
        while True:
            with self.cond:
                if self.i > self.n:
                    break
                self.cond.wait_for(lambda: (self.i - 1) // 5 % 3 == 0 or self.i > self.n)
                if self.i <= self.n:
                    print_first(self.i)
                self.i += 1
                self.cond.notify(2)

    def second(self, print_second):
        while True:
            with self.cond:
                if self.i > self.n:
                    break
                self.cond.wait_for(lambda: (self.i - 1) // 5 % 3 == 1 or self.i > self.n)
                if self.i <= self.n:
                    print_second(self.i)
                self.i += 1
                self.cond.notify(2)
                
    def third(self, print_third):
        while True:
            with self.cond:
                if self.i > self.n:
                    break
                self.cond.wait_for(lambda: (self.i - 1) // 5 % 3 == 2 or self.i > self.n)
                if self.i <= self.n:
                    print_third(self.i)
                self.i += 1
                self.cond.notify(2)
