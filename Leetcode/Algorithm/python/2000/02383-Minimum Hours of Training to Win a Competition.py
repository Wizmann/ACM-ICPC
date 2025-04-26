class Solution(object):
    def minNumberOfHours(self, initialEnergy, initialExperience, energy, experience):
        n = len(energy)
        assert len(experience) == n
        res = 0
        for i in xrange(n):
            a, b = energy[i], experience[i]
            if a >= initialEnergy:
                delta = a - initialEnergy + 1
                res += delta
                initialEnergy += delta
            initialEnergy -= a
            if b >= initialExperience:
                delta = b - initialExperience + 1
                res += delta
                initialExperience += delta
            initialExperience += b
        return res
                
