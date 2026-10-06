class Solution:
    # @param {integer[]} nums
    # @return {string}
    def largestNumber(self, nums):
        return str(int(''.join(
            sorted(map(str, nums),
                cmp=lambda x, y: int(x + y) - int(y + x),
                reverse=True
            )
        )))
