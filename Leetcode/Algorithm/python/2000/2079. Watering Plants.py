class Solution(object):
    def wateringPlants(self, plants, capacity):
        cur = capacity
        step = 0
        for i, plant in enumerate(plants):
            if plant > cur:
                cur = capacity - plant
                step += i * 2 + 1
            else:
                cur -= plant
                step += 1
        return step
            
