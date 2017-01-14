import sys
(sx, sy, tx, ty) = map(int, raw_input().split())
 
dx, dy = tx - sx, ty - sy
 
 
for i in xrange(dy):
    sys.stdout.write('U')
for i in xrange(dx):
    sys.stdout.write('R')
    
###
 
for i in xrange(dy):
    sys.stdout.write('D')
for i in xrange(dx):
    sys.stdout.write('L')
 
###
 
 
sys.stdout.write('L')
 
for i in xrange(dy + 1):
    sys.stdout.write('U')
for i in xrange(dx + 1):
    sys.stdout.write('R')
    
sys.stdout.write('D')
 
###
sys.stdout.write('R')
 
for i in xrange(dy + 1):
    sys.stdout.write('D')
for i in xrange(dx + 1):
    sys.stdout.write('L')
    
sys.stdout.write('U')
sys.stdout.write('\n')
