class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int K, int V) {
        int n = heights.size();
        while (K--) {
            int h = heights[V];
            int pos = -1;
            int low = h;
            for (int i = V - 1; i >= 0; i--) {
                if (heights[i] > low) {
                    break;
                }
                if (heights[i] < low) {
                    pos = i;
                    low = heights[i];
                }
            }
        
            if (pos == -1) {
                for (int i = V + 1; i < n; i++) {
                    if (heights[i] > low) {
                        break;
                    }
                    if (heights[i] < low) {
                        pos = i;
                        low = heights[i];
                    }
                }
            }
            if (pos == -1) {
                heights[V]++;
            } else {
                heights[pos]++;
            }
        }
        return heights;
    }
};
