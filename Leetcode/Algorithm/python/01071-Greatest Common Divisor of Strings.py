class Solution(object):
    def gcdOfStrings(self, str1, str2):
        if str1 == str2:
            return str1
        elif not str1 or not str2:
            return ''
        elif str1.startswith(str2):
            return self.gcdOfStrings(str1[len(str2):], str2)
        elif str2.startswith(str1):
            return self.gcdOfStrings(str1, str2[len(str1):])
        else:
            return ''
            
