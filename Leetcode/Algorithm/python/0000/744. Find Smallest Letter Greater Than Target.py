class Solution(object):
    def nextGreatestLetter(self, letters, target):
        return min(filter(lambda x: x > target, letters) or letters)
