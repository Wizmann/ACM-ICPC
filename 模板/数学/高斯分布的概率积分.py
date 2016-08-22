import scipy.stats

print scipy.stats.norm(30, 4).cdf(40)
print 1.0  - scipy.stats.norm(30, 4).cdf(21)
print scipy.stats.norm(30, 4).cdf(35) - scipy.stats.norm(30, 4).cdf(30)

'''
0.993790334674
0.987775527345
0.394350226333
'''
