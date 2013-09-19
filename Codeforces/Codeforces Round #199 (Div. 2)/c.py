# Sep 7, 2013 2:21:21 PM	Wizmann	 342C - Cupboard and Balloons	 Python 2	Accepted	 62 ms	 0 KB

from math import *

(r, h) = map(int, raw_input().split())

s = 0
s += h / r * 2

if (h - (h / r) * r) * 2 < r:
	s += 1
else:
	delta = h - (h / r) * r

	x = sqrt(delta ** 2 + (r / 2.) ** 2)

	if x >= r:
		s += 3
	else:
		s += 2

print s
