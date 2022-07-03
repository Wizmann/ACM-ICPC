import string
class Solution(object):
    def strongPasswordCheckerII(self, password):
        n = len(password)

        if n < 8:
            return False

        s = set(password)

        if not set(string.ascii_lowercase) & s:
            return False

        if not set(string.ascii_uppercase) & s:
            return False

        if not set(string.digits) & s:
            return False

        if not set("!@#$%^&*()-+") & s:
            return False


        for i in xrange(n - 1):
            if password[i] == password[i + 1]:
                return False

        return True


'''
^^^^TEST^^^^
"IloveLe3tcode!"
-----------------
true
$$$TEST$$$$
'''

        
