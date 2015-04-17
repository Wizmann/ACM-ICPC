nums =  ["zero","one","two","three","four","five","six","seven","eight","nine"]
 
class Solution:
    def readSum(self,n):
        s = sum(map(int, n))
        s = list(map(int, str(s)))
        return ' '.join(map(lambda x: nums[x], s))
        
        
S = Solution()
print S.readSum('987654321')
