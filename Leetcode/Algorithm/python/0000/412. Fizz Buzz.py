class Solution(object):
    def fizzBuzz(self, n):
        return [('Fizz' if i % 3 == 0 else '') 
                + ('Buzz' if i % 5 == 0 else '') 
                + (str(i) if i % 3 != 0 and i % 5 != 0 else '')
                for i in xrange(1, n + 1)]
