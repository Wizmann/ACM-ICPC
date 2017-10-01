template <typename T>
class Counter {
public:
    Counter(): unique_cnt(0) {
        // pass
    }
    
    void add(T item) {
        if (mp[item] == 1) {
            unique_cnt--;
        }
        mp[item]++;
        if (mp[item] == 1) {
            unique_cnt++;
        } 
    }
    
    void remove(T item) {
        if (mp[item] == 1) {
            unique_cnt--;
        }
        mp[item]--;
        if (mp[item] == 1) {
            unique_cnt++;
        }
    }
    
    int get_unique_cnt() {
        return unique_cnt;
    }
    
    size_t size() {
        return mp.size();
    }
private:
    int unique_cnt;
    map<T, int> mp;
};

class Solution {
public:
    /*
     * @param : the given array
     * @param : the window size
     * @return: the sum of the count of unique elements in each window
     */
    int slidingWindowUniqueElementsSum(vector<int> nums, int k) {
        Counter<int> cnt;
        int n = nums.size();
        for (int i = 0; i < min(n, k); i++) {
            int cur = nums[i];
            cnt.add(cur);
        }
        int ans = cnt.get_unique_cnt();
        cout << cnt.get_unique_cnt() << endl;

        for (int i = k; i < n; i++) {
            cnt.remove(nums[i - k]);
            cnt.add(nums[i]);
            cout << cnt.get_unique_cnt() << endl;
            ans += cnt.get_unique_cnt();
        }
        return ans;
    }
};
