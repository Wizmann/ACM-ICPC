#coding=utf-8

import os
import subprocess
from random import randint

def inputGen(idx):
    with open('input_%d.txt' % idx, 'w') as f:
        if idx == 0:
            f.write('13\n')
        elif idx == 1:
            f.write('23456\n')
        elif idx < 10:
            n = randint(1, 100000)
            f.write('%d\n' % n)
        else:
            n = randint(19999, 100000)
            f.write('%d\n' % n)

def outputGen(idx):
    subprocess.check_call('python sqfib.py < input_%d.txt > output_%d.txt' % (idx, idx), shell=True)


N = 20

for i in xrange(N):
    inputGen(i)
    outputGen(i)
