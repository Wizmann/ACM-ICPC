class StockSpanner {
public:
    StockSpanner(): idx(1) {
        // pass
    }
    
    int next(int price) {
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }
        int res = idx - (st.empty()? 0: st.top().second);
        st.push({price, idx});
        idx++;
        return res;
    }
private:
    int idx;
    stack<pair<int, int> > st;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
