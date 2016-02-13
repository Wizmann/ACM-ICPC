class Solution:
	# @param {int} n an integer
	# @return {boolean} true if this is a happy number or false
	def isHappy(self, n):
		# Write your code here
		f = lambda x: sum(map(lambda y: y * y, map(int, str(x))))
		s = set()
		
		while n != 1 and n not in s:
			s.add(n)
			n = f(n)
		return n == 1