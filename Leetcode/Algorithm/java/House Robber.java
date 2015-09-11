public class Solution {
    public int rob(int[] nums) {
        int A = 0;
        int B = 0;
        for (int num: nums) {
            int _A = num + B;
            int _B = Math.max(A, B);
            
            A = _A;
            B = _B;
        }
        return Math.max(A, B);
    }
}
