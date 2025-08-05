class FreqStack {
public:
    FreqStack() {
        incid = 0;
    }
    
    void push(int x) {
        int f = mp[x];
        st[f + 1].insert({++incid, x});
        mp[x]++;
    }
    
    int pop() {
        auto iter1 = prev(st.end());
        auto& pairs = iter1->second;
        auto iter2 = prev(pairs.end());
        int v = iter2->second;
        pairs.erase(iter2);
        if (pairs.empty()) {
            st.erase(iter1);
        }
        mp[v]--;
        return v;
    }
private:
    int incid;
    map<int, int> mp;
    map<int, set<pair<int, int> > > st;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
