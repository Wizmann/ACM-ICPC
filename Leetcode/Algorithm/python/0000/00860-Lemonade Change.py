class Solution(object):
    def lemonadeChange(self, bills):
        col = [0, 0, 0]
        
        flag = True
        for bill in bills:
            if bill == 5:
                col[0] += 1
            elif bill == 10:
                if col[0] > 0:
                    col[0] -= 1
                    col[1] += 1
                else:
                    flag = False
                    break
            elif bill == 20:
                if col[0] > 0 and col[1] > 0:
                    col[0] -= 1
                    col[1] -= 1
                    col[2] += 1
                elif col[0] >= 3:
                    col[0] -= 3
                    col[2] += 1
                else:
                    flag = False
                    break
            else:
                print 'invalid input'
                break
        return flag
    
assert Solution().lemonadeChange([]) == True
assert Solution().lemonadeChange([5]) == True
assert Solution().lemonadeChange([5, 10]) == True
assert Solution().lemonadeChange([5, 5]) == True
assert Solution().lemonadeChange([5, 10, 20]) == False
assert Solution().lemonadeChange([5, 10, 5, 20]) == True
