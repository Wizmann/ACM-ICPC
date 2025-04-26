class Solution(object):
    def sortPeople(self, names, heights):
        return map(lambda x: x[1], sorted(zip(heights, names), reverse=True))
