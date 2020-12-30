class Solution(object):
    def addToArrayForm(self, A, K):
        return map(
            int, 
            str(
                int(''.join(map(str, A))) + K
            )
        )
