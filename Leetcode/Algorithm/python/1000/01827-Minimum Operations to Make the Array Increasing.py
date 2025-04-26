class Solution(object):
    def minOperations(self, nums):
        res = 0
        pre = 0
        for num in nums:
            if num <= pre:
                res += (pre + 1 - num)
                pre = pre + 1
            else:
                pre = num
        return res

'''
^^^^TEST^^^
[1,1,1]
-------
3
$$$TEST$$$$

^^^^TEST^^^
[1,5,2,4,1]
-------
14
$$$TEST$$$$

^^^^TEST^^^
[8]
-------
0
$$$TEST$$$$
'''
