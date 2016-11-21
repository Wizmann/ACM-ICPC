class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool res = !exists(val);
        nums.push_back(
            mp.insert({val, nums.size()})
        );
        return res;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!exists(val)) {
            return false;
        }
        auto range = mp.equal_range(val);
        int idx = (range.first)->second;
        
        swap(nums[idx], *nums.rbegin());

        mp.erase(range.first);
        nums.pop_back();
        
        cout << idx << endl;
        
        if (idx < nums.size()) {
            nums[idx]->second = idx;
        }
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx = random() % nums.size();
        return nums[idx]->first;
    }
private:
    bool exists(int val) {
        auto range = mp.equal_range(val);
        if (range.first == range.second) {
            return false;
        }
        return true;
    }
    
private:
    vector<unordered_map<int, int>::iterator> nums;
    unordered_multimap<int, int> mp;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
