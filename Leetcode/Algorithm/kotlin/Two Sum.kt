class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        var mp = HashMap<Int, Int>()
        for (i in nums.indices) {
            if (mp.containsKey(target - nums[i])) {
                return intArrayOf(mp[target - nums[i]]!!, i)
            }
            mp[nums[i]] = i
        }
        return intArrayOf(-1, -1)
    }
}
