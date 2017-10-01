class Solution:
    """
    @param: : a given string
    @param: : another given string
    @return: An array of missing string
    """

    def missingString(self, str1, str2):
        s2 = set(str2.split())
        
        return [s for s in str1.split() if s not in s2]
