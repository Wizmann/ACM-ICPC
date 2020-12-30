const int INF = 0x3f3f3f3f;

class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
        idx = 0;
    }
    
    void push(int x) {
        int u = idx++;
        pair<int, int> v = {x, u};
        st.push_back(v);
        mp[v] = --st.end();
    }
    
    int pop() {
        auto p = *st.rbegin();
        st.pop_back();
        mp.erase(mp.find(p));
        return p.first;
    }
    
    int top() {
        return st.rbegin()->first;
    }
    
    int peekMax() {
        return mp.rbegin()->first.first;
    }
    
    int popMax() {
        int u = peekMax();
        auto iter = mp.lower_bound({u, INF});
        --iter;
        auto jter = iter->second;
        mp.erase(iter);
        st.erase(jter);
        return u;
    }
private:
    list<pair<int, int> > st;
    map<pair<int, int>, list<pair<int, int> >::iterator> mp;
    int idx;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */
