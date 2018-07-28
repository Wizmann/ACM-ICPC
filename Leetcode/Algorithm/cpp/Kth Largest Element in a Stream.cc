class KthLargest {
public:
    KthLargest(int k_, vector<int> nums) {
        st.clear();
        k = k_;
        
        for (auto num: nums) {
            add(num);
        }
    }
    
    int add(int val) {
        st.insert(val);
        if (st.size() > k) {
            st.erase(st.begin());
        }
        return *st.begin();
    }
private:
    int k;
    multiset<int> st;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
