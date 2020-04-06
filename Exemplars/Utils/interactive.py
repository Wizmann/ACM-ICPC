import subprocess
import select
import sys

def print_and_flush(owner, line):
    print owner, '>>', line.strip()
    sys.stdout.flush()

judge, solution = sys.argv[1], sys.argv[2]

p1 = subprocess.Popen(judge, stdout=subprocess.PIPE, stdin=subprocess.PIPE, shell=True)
p2 = subprocess.Popen(solution, stdout=subprocess.PIPE, stdin=subprocess.PIPE, shell=True)

while p1.poll() is None and p2.poll() is None:
    fds = select.select([p1.stdout, p2.stdout], [], [], 0)[0]
    for fd in fds:
        if fd is p1.stdout:
            line = fd.readline()
            print_and_flush('judge', line)
            p2.stdin.write(line)
        elif fd is p2.stdout:
            line = fd.readline()
            print_and_flush('solution', line)
            p1.stdin.write(line)
        else:
            assert False
