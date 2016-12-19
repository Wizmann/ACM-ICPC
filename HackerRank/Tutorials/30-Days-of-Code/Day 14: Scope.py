class Difference:
    def __init__(self, a):
        self.__elements = a
        
    def computeDifference(self):
        pass
    
    @property
    def maximumDifference(self):
        return max(self.__elements) - min(self.__elements)
        
    # End of Difference class

_ = raw_input()
a = [int(e) for e in raw_input().split(' ')]

d = Difference(a)
d.computeDifference()

print d.maximumDifference
