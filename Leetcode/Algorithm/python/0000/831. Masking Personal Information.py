class Solution(object):
    def maskPII(self, S):
        if '@' in S:
            return self.maskMailAddress(S)
        else:
            return self.maskPhoneNumber(S)
        
    def maskMailAddress(self, S):
        a, b = S.lower().split('@')
        return a[0] + '*' * 5 + a[-1] + '@' + b
    
    def maskPhoneNumber(self, S):
        nums = filter(lambda c: c.isdigit(), S)
        if len(nums) > 10:
            return "+" + '*' * (len(nums) - 10) + "-***-***-" + nums[-4:]
        else:
            return "***-***-" + nums[-4:]
