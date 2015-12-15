class Solution:
    # @param {string} digits A digital string
    # @return {string[]} all posible letter combinations
    def letterCombinations(self, digits):
        self.keyboard = {
            2: 'abc',
            3: 'def',
            4: 'ghi',
            5: 'jkl',
            6: 'mno',
            7: 'pqrs',
            8: 'tuv',
            9: 'wxyz'
        }
        self.res = []
        self.buffer = []
        self.dfs(digits)
        return self.res

    def dfs(self, digits):
        if not digits:
            s = ''.join(self.buffer)
            if s:
                self.res.append(s)
            return
        d = int(digits[0])
        for item in self.keyboard[d]:
            self.buffer.append(item)
            self.dfs(digits[1:])
            self.buffer.pop()
