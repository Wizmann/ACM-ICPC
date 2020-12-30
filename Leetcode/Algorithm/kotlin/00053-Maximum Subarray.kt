val INF = Int.MIN_VALUE

class Solution {
    fun maxSubArray(nums: IntArray): Int {
        var n = nums.size
        var l = 0
        var r = 0
        var tot = 0
        var res = -INF
        while (l < n && r < n) {
            tot += nums[r]
            r += 1
            res = maxOf(res, tot)
            if (tot <= 0) {
                tot = 0
                l = r
            }
        }
        return res
    }
}
