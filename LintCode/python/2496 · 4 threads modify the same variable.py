# you can import any package that you need here
# write your code here

from threading import Lock

class VariableModification:
    def __init__(self):
        self.i = 0
        self.lock = Lock()

    def add_1(self, increase: callable) -> None:
        self.lock.acquire()
        self.i = increase(self.i)
        self.lock.release()

    def add_2(self, increase: callable) -> None:
        self.lock.acquire()
        self.i = increase(self.i)
        self.lock.release()

    def sub_1(self, decrease: callable) -> None:
        self.lock.acquire()
        self.i = decrease(self.i)
        self.lock.release()

    def sub_2(self, decrease: callable) -> None:
        self.lock.acquire()
        self.i = decrease(self.i)
        self.lock.release()

    def check_i(self) -> int:
        return self.i
