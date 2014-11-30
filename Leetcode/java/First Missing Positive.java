public class Solution {
    public int firstMissingPositive(int[] num) {
        int n = num.length;
        
        for (int i = 0; i < n; i++) {
            while (num[i] != i + 1 && num[i] > 0 && num[i] <= n) {
                if (num[num[i] - 1] == num[i]) {
                    break;
                }
                int tmp = num[num[i] - 1];
                num[num[i] - 1] = num[i];
                num[i] = tmp;
            }
        }
        int miss = n + 1;
        for (int i = 0; i < n; i++) {
            if (num[i] != i + 1) {
                miss = i + 1;
                break;
            }
        }
        return miss;
    }
}
