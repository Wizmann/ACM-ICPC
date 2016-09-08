import numpy
from scipy import stats

n = int(raw_input())
ns = map(int, raw_input().split())

print "%.1f" % numpy.mean(ns)
print "%.1f" % numpy.median(ns)
print "%d" % stats.mode(ns)[0]
