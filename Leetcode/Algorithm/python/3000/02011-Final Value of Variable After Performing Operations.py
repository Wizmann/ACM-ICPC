class Solution(object):
    def finalValueAfterOperations(self, operations):
        return eval(''.join(map(lambda x: x.replace('X', '')
                       .replace('++', '+1').replace('--', '-1'), operations)))