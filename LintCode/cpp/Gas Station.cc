class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer 
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int g = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            g += gas[i];
            g -= cost[i];
            
            if (g < 0) {
                g = 0;
                ans = (i + 1) % n;
            }
        }
        
        g = 0;
        for (int i = 0; i < n; i++) {
            int p = (ans + i) % n;
            g += gas[p];
            g -= cost[p];
            if (g < 0) {
                return -1;
            }
        }
        return ans;
    }
};
