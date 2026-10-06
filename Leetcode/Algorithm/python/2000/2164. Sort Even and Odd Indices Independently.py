#coding=utf-8
#python3

import itertools
from itertools import chain

class Solution:
    def sortEvenOdd(self, nums: List[int]) -> List[int]:
        odds = sorted(nums[1::2], reverse=True)
        evens = sorted(nums[::2])

        return list(filter(lambda x: x,
            chain.from_iterable(itertools.zip_longest(evens, odds))))

'''
^^^TEST^^^
[4, 1, 2, 3]
------
[2, 3, 4, 1]
$$$TEST$$$

^^^TEST^^^
[2,1]
------
[2,1]
$$$TEST$$$

^^^TEST^^^
[2,1,3]
------
[2,1,3]
$$$TEST$$$

^^^TEST^^^
[36,45,32,31,15,41,9,46,36,6,15,16,33,26,27,31,44,34]
------
[9,46,15,45,15,41,27,34,32,31,33,31,36,26,36,16,44,6]
$$$TEST$$$
'''
