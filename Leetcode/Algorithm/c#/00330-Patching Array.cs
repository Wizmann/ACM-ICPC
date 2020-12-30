public class Solution {
    public const long INF = 0x3f3f3f3f3f3f3f3f;
    public int MinPatches(int[] nums, int k) {
        long sum = 0;
        int ans = 0;
        int ptr = 0;
        int n = nums.Length;
        
        while (sum < k) {
            long num = ptr < n? nums[ptr]: INF;
            
            if (num <= sum + 1) {
                sum += num;
                ptr++;
            } else {
                ans++;
                sum += sum + 1;
            }
        }
        return ans;
    }
}
