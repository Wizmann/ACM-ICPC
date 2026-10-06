class Solution(object):
    def peopleIndexes(self, favoriteCompanies):
        n = len(favoriteCompanies)
        res = []
        for i in xrange(n):
            for j in xrange(n):
                if i == j:
                    continue
                u = set(favoriteCompanies[i]) & set(favoriteCompanies[j])
                if u == set(favoriteCompanies[i]):
                    break
            else:
                res.append(i)
        return res
                    
