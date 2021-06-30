# you can import any package that you need here
# -- write your code here --

import sys
from threading import Thread

def run_print_in_thread(print_hello_world):
    t = Thread(target=print_hello_world)
    t.start()
    t.join()
