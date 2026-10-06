class Solution(object):
    def distMoney(self, money, children):
        u = money / 8
        if 8 * children == money:
            return children
        elif 8 * children < money:
            return children - 1
        else:
            money -= u * 8
            rem = children - u
            while money < rem:
                money += 8
                u -= 1
                rem += 1
            if rem == 1 and money == 4:
                u -= 1
            return max(-1, u)
