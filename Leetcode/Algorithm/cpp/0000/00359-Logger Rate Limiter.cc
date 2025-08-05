class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        while (!q.empty() && timestamp - q.front().first >= 10) {
            auto s = q.front().second;
            q.pop();
            st.erase(st.find(s));
        }
        if (st.find(message) != st.end()) {
            return false;
        }
        st.insert(message);
        q.push({timestamp, message});
        return true;
    }
private:
    queue<pair<int, string> > q;
    multiset<string> st;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */
