# interactive tester for some GCJ problems

import sys
import subprocess
from subprocess import Popen, PIPE
import time

now = time.time()
timestamp = time.strftime('%y%m%d%H%M%S',time.localtime(now))

ping, pong = sys.argv[1], sys.argv[2]

p1 = Popen('python ' + ping + ' 1', stdin=PIPE, stdout=PIPE, stderr=subprocess.STDOUT, shell=True)
p2 = Popen('python ' + pong, stdin=PIPE, stdout=PIPE, stderr=subprocess.STDOUT, shell=True)

with open('ping.%s.txt' % timestamp, 'w') as pingfile:
    with open('pong.%s.txt' % timestamp, 'w') as pongfile:
        while True:
            # add any filtering code if you like
            ping = p1.stdout.readline()
            print 'ping:', repr(ping.strip())
            pingfile.write(ping)
            p2.stdin.write(ping)

            # add any filtering code if you like
            pong = p2.stdout.readline()
            print 'pong: ', pong.strip()
            pongfile.write(pong)
            p1.stdin.write(pong)

            # flush the output to file
            pingfile.flush()
            pongfile.flush()
