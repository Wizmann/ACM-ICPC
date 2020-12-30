public class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int cur = 0;
        int res = 0;
        int n = gas.length;
        for (int i = 0; i < 2 * n; i++) {
            if (cur < 0) {
                cur = 0;
                res = i;
            }
            cur += gas[i % n];
            cur -= cost[i % n];
        }
        return res >= n? -1: res;
    }
}
