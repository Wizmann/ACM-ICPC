class Solution(object):
    def filterRestaurants(self, restaurants, veganFriendly, maxPrice, maxDistance):
        if veganFriendly:
            restaurants = filter(lambda r: r[2], restaurants)
        restaurants = filter(lambda r: r[3] <= maxPrice, restaurants)
        restaurants = filter(lambda r: r[4] <= maxDistance, restaurants)
        restaurants.sort(key=lambda r: (r[1], r[0]), reverse=True)
        return map(lambda r: r[0], restaurants)
