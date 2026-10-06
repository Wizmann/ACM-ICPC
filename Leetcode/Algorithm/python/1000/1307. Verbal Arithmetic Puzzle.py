class Solution(object):
    def isSolvable(self, words, result):
        st = set(range(10))
        return self.dfs(0, 0, {}, st, map(lambda word: word[::-1], words), result[::-1])

    def toNum(self, word, d):
        res = ''
        for c in word:
            res += str(d[c])
        return res
    
    def dfs(self, cur, g, d, st, words, result):
        if cur > len(result) + 1:
            nums = []
            for word in words:
                num = self.toNum(word, d)
                if num[-1] == '0':
                    return False
                nums.append(num)
            res = self.toNum(result, d)
            if res[-1] == '0':
                return False
            print nums, res[::-1]
            return True
        
        for word in words + [result]:
            if len(word) > cur:
                if word[cur] not in d:
                    rem = list(st)
                    flag = False
                    for num in rem:
                        d[word[cur]] = num
                        st.remove(num)
                        flag |= self.dfs(cur, g, d, st, words, result)
                        del d[word[cur]]
                        st.add(num)
                        if flag:
                            break
                    return flag
        
        l, r = 0, 0
        for word in words:
            if len(word) > cur:
                l += d[word[cur]]
        l += g
        if len(result) > cur:
            r = d[result[cur]]
        #print cur, l, r
        
        if l % 10 == r:
            return self.dfs(cur + 1, l / 10, d, st, words, result)
        else:
            return False
