import heapq
from collections import defaultdict

class Twitter(object):

    def __init__(self):
        self.relationship = defaultdict(set)
        self.posts = defaultdict(list)
        self.idx = 0

    def postTweet(self, userId, tweetId):
        self.posts[userId].append((self.idx, tweetId))
        self.idx += 1
        

    def getNewsFeed(self, userId):
        followees = set(list(self.relationship[userId]) + [userId])
        
        pq = []
        for followee in followees:
            if not self.posts[followee]:
                continue
            posts = self.posts[followee]
            pq.append((-posts[-1][0], len(posts) - 1, followee))
        
        heapq.heapify(pq)
        
        res = []
        while len(res) < 10 and pq:
            idx, ptr, userId = heapq.heappop(pq)
            res.append(self.posts[userId][ptr][1])
            ptr -= 1
            if ptr >= 0:
                heapq.heappush(pq, (-self.posts[userId][ptr][0], ptr, userId))
        return res        

    def follow(self, followerId, followeeId):
        self.relationship[followerId].add(followeeId)
        

    def unfollow(self, followerId, followeeId):
        if followeeId in self.relationship[followerId]:
            self.relationship[followerId].remove(followeeId)

# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
