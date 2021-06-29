# you can import any package that you need here
# write your code here

from threading import Lock, Condition

class Bank:
    def __init__(self, account: int = 0):
        self.account = account
        self.lock = Lock()
        self.cond = Condition(self.lock)

    def save_money(self, save_operation, amount: int) -> None:
        self.lock.acquire()
        self.account = save_operation(self.account, amount)
        self.cond.notify()
        self.lock.release()
        

    def withdraw_money(self, withdraw_operation, amount: int) -> None:
        with self.cond:
            self.cond.wait_for(lambda: self.account >= amount)
            self.account = withdraw_operation(self.account, amount)
       
    def check_account(self) -> int:
        self.lock.acquire()
        res = self.account
        self.lock.release()
        return res
