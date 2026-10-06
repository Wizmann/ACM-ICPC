class MyCalendar(object):

    def __init__(self):
        self.booked = []

    def book(self, start, end):
        if self.can_book(start, end):
            self.booked.append((start, end - 1))
            return True
        return False
    
    def can_book(self, start, end):
        end -= 1
        for (a, b) in self.booked:
            if not(end < a or start > b):
                return False
        return True


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)
