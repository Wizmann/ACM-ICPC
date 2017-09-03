class Solution:
    """
    @param: numbers: An array of Integer
    @param: target: target = numbers[index1] + numbers[index2]
    @return: [index1 + 1, index2 + 1] (index1 < index2)
    """
    def twoSum(self, numbers, target):
        d = {}
        for i, num in enumerate(numbers):
            if target - num in d:
                return [ d[target - num] + 1, i + 1 ]
            d[num] = i
        return [ -1, -1 ]
