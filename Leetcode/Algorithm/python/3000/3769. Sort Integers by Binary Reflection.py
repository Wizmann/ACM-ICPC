class Solution(object):
    def sortByReflection(self, nums):
        nums.sort(key=lambda num: (int('{:b}'.format(num)[::-1], 2), num))
        return nums
