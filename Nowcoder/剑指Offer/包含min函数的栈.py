# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.st = []
        self.mini = []
        
    def push(self, node):
        self.st.append(node)
        if not self.mini or node < self.mini[-1]:
            self.mini.append(node)
        else:
            self.mini.append(self.mini[-1])
    def pop(self):
        res = self.st.pop()
        self.mini.pop()
        return res
    def top(self):
        return self.st[-1]
    def min(self):
        return self.mini[-1]
