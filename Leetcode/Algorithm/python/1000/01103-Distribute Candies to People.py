class Solution(object):
    def distributeCandies(self, candies, num_people):
        res = [0 for i in xrange(num_people)]
        i = 0
        while candies:
            if i + 1 <= candies:
                res[i % num_people] += i + 1
            else:
                res[i % num_people] += candies
            candies = max(0, candies - i - 1)
            i += 1
        return res
