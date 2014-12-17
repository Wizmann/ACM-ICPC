class Solution:              
    # @param a, a string     
    # @param b, a string     
    # @return a boolean      
    def compareVersion(self, version1, version2):  
        l1, l2 = map(int, version1.split('.')), map(int, version2.split('.'))
 
        max_len = max(len(l1), len(l2))            
 
        for i in xrange(max_len):
            a, b = 0, 0      
            if i < len(l1):  
                a = l1[i]    
            if i < len(l2):  
                b = l2[i]    

            if a != b: 
                return -1 if a < b else 1 
 
        return 0
