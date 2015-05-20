def main():
	n = int(raw_input())
	s = raw_input()
	
	if n > len(set(s)):
		print 'NO'
		return
	
	print 'YES'
	ss = map(lambda x: x[1], 
	     	sorted(
	     		dict(
	     			map(lambda (a, b): (b, a), enumerate(s))[::-1]
	     		).items(),
	     	key=lambda x: x[0]))
	ss.append(len(s))
	ss.sort()
	for i in xrange(n - 1):
		print s[ss[i]:ss[i + 1]]
	print s[ss[n - 1]:]
	
if __name__ == '__main__':
	main()