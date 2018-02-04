class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
		int n = arr.size();
        vector<int> pos(n, 0);
		for (int i = 0; i < n; i++) {
			pos[arr[i]] = i;
		}
		
		int l = 0;
		int r = -1;
		int cnt = 0;
		int ans = 0;
		
		for (int i = 0; i < n; i++) {
			r = max(r, pos[i]);
			cnt++;
			if (r - l + 1 == cnt) {
				ans++;
				l = i + 1;
				r = -1;
				cnt = 0;
			}
		}
		return ans;
    }
};
