class ParkingSystem(object):

    def __init__(self, big, medium, small):
        self.slots = [0, big, medium, small]
        

    def addCar(self, carType):
        if self.slots[carType] == 0:
            return False
        else:
            self.slots[carType] -= 1
            return True


# Your ParkingSystem object will be instantiated and called as such:
# obj = ParkingSystem(big, medium, small)
# param_1 = obj.addCar(carType)
