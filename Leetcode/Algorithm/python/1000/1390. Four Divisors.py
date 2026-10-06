class Solution(object):
    def sumFourDivisors(self, nums):
        res = 0
        for num in nums:
            divs = self.find_divs(num)
            if len(divs) == 4:
                res += sum(divs)
        return res
    
    def find_divs(self, num):
        st = set()
        i = 1
        while i * i <= num:
            if num % i == 0:
                st.add(i)
                st.add(num / i)
            i += 1
        return st
