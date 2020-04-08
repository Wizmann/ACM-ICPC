# https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/

class Solution(object):
    def numSteps(self, s):
        step = 0
        s = list(s)
        while s != ['1']:
            # print s, step
            if s[-1] == '0':
                s = s[:-1]
                step += 1
            else:
                while s and s[-1] == '1':
                    s = s[:-1]
                    step += 1
                if not s:
                    s = ['']
                s[-1] = '1'
                step += 1
        return step
