# 傻逼题目
my = [1, 0, -1, 0]
mx = [0, 1, 0, -1]

dir_string = ['North', 'East', 'South', 'West']

class Robot(object):

    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.dir = 1
        self.y = 0
        self.x = 0
        
    def step(self, num):
        # print num
        if num:
            if (self.y in (0, self.height - 1) and self.dir in (1, 3)) or (self.x in (0, self.width - 1) and self.dir in (0, 2)):
                num %= (self.width + self.height - 2) * 2
                if num == 0:
                    if (self.x, self.y) == (0, 0):
                        self.dir = 2
                    elif (self.x, self.y) == (0, self.height - 1):
                        self.dir = 3
                    elif (self.x, self.y) == (self.width - 1, 0):
                        self.dir = 1
                    elif (self.x, self.y) == (self.width - 1, self.height - 1):
                        self.dir = 0
                    
        while num:
            # print self.dir, self.x, self.y,
            num = self.do_step(num)
            # print self.x, self.y
            
    def do_step(self, num):
        ny = self.y + my[self.dir] * num
        nx = self.x + mx[self.dir] * num
        
        if 0 <= nx < self.width and 0 <= ny < self.height:
            self.y = ny
            self.x = nx
            return 0
        else:
            self.dir = (self.dir - 1 + 4) % 4
            if nx < 0:
                self.x = 0
                self.y = ny
                return -nx
            elif nx >= self.width:
                self.x = self.width - 1
                self.y = ny
                return nx - self.width + 1
            elif ny < 0:
                self.x = nx
                self.y = 0
                return -ny
            elif ny >= self.height:
                self.x = nx
                self.y = self.height - 1
                return ny - self.height + 1
            else:
                assert False

    def getPos(self):
        return (self.x, self.y)

    def getDir(self):
        return dir_string[self.dir]
        


# Your Robot object will be instantiated and called as such:
# obj = Robot(width, height)
# obj.step(num)
# param_2 = obj.getPos()
# param_3 = obj.getDir()
