class Solution:
    """
    @param: A: An array of non-negative integers
    @return: The maximum amount of money you can rob tonight
    """
    def houseRobber(self, A):
        a, b = 0, 0
        for house in A:
            a, b = max(a, b), a + house
        return max(a, b)
