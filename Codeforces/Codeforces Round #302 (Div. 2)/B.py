def main():
	(n, k) = map(int, raw_input().split())

	maxi = ((n * n) + 1) / 2
	
	if k > maxi:
		print 'NO'
		return
	print 'YES'
	g = [
			['S' for i in xrange(n)]
			for j in xrange(n)
		]
	
	for i in xrange(0, n):
		if k == 0:
			break
		for j in xrange(i % 2, n, 2):
			if k == 0:
				break
			g[i][j] = 'L'
			k -= 1
	
	for line in g:
		print ''.join(line)
		
if __name__ == '__main__':
	main()