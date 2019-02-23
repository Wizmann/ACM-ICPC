# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.st1, self.st2 = [], []
    
    def push(self, node):
        self.st2.append(node)
        
    def pop(self):
        if not self.st1:
            while self.st2:
                self.st1.append(self.st2.pop())
        return self.st1.pop()
