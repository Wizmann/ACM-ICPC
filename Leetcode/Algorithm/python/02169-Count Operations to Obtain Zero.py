class Solution(object):
    def countOperations(self, num1, num2):
        step = 0
        while num1 and num2:
            if num1 < num2:
                num1, num2 = num2, num1
            num1 -= num2
            step += 1
        return step
