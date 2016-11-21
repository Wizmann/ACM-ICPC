class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (st.find(val) == st.end()) {
            nums.push_back(val);
            st.insert({val, nums.size() - 1});
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (st.find(val) == st.end()) {
            return false;
        }
        int idx = st[val];
        swap(nums[idx], *nums.rbegin());
        st[nums[idx]] = idx;
        st.erase(st.find(val));
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx = random() % nums.size();
        return nums[idx];
    }
    
private:
    vector<int> nums;
    unordered_map<int, int> st;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
