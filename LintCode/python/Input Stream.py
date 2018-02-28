class Solution:
    """
    @param inputA: Input stream A
    @param inputB: Input stream B
    @return: The answer
    """
    def inputStream(self, inputA, inputB):
        A = self.get_last_char(inputA)
        B = self.get_last_char(inputB)

        return 'YES' if A == B else 'NO'
        
    def get_last_char(self, stream):
        res = []
        for c in stream:
            if c == '<':
                if res:
                    res.pop()
            else:
                res.append(c)
        return res
