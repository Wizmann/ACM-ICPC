class Solution(object):
    def sortArrayByParity(self, A):
        return filter(lambda x: x % 2 == 0, A) + filter(lambda x: x % 2 == 1, A)
        
