from threading import Lock, Condition

class Solution:
    def __init__(self, n):
        self.n = n
        self.i = 0
        self.lock = Lock()
        self.cond = Condition(self.lock)

    def print_As(self, print_A):
        while self.i < self.n * 3:
            with self.cond:
                self.cond.wait_for(lambda: self.i == self.n * 3 or self.i % 3 == 0)
                if self.i < self.n * 3:                
                    print_A()
                else:
                    break
                self.i += 1
                # because we can't ensure which thread (print_B or print_C) is the next thread 
                # in the waiting queue, we'd better notify both of them rather than only one
                self.cond.notify(2)
    
    def print_Bs(self, print_B):
        while self.i < self.n * 3:
            with self.cond:
                self.cond.wait_for(lambda: self.i == self.n * 3 or self.i % 3 == 1)
                if self.i < self.n * 3:                
                    print_B()
                else:
                    break
                self.i += 1
                self.cond.notify(2)

    def print_Cs(self, print_C):
        while self.i < self.n * 3:
            with self.cond:
                self.cond.wait_for(lambda: self.i == self.n * 3 or self.i % 3 == 2)
                if self.i < self.n * 3:                
                    print_C()
                self.i += 1
                if self.i == self.n * 3:
                    self.cond.notify_all()
                    break
                self.cond.notify(2)
