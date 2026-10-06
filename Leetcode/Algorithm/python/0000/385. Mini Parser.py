# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger(object):
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

import re

class Solution(object):
    def tokenize(self, line):
        return filter(lambda x: x and x != ',', re.split('(-?\d+|\[|\])', line))
    
    def deserialize(self, s):
        self.s = self.tokenize(s)
        if len(self.s) == 1:
            return NestedInteger(int(s))
        self.s = self.s[1:]
        return self.do_deserialize()
        
    def do_deserialize(self):
        ni = NestedInteger()
        while self.s:
            cur = self.s.pop(0)
            
            if self.is_int(cur):
                ni.add(int(cur))
            elif cur == ']':
                break
            elif cur == '[':
                ni.add(self.do_deserialize())
        return ni
        
    def is_int(self, value):
        try:
            value = int(value)
            return True
        except:
            return False
