class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if (lpq.empty()) {
            lpq.push(num);
        } else if (num > lpq.top()) {
            rpq.push(num);
        } else {
            lpq.push(num);
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        adjust();
        if (lpq.size() == rpq.size()) {
            int l = lpq.top();
            int r = rpq.top();
            return 0.5 * (l + r);
        } else {
            return lpq.top();
        }
    }
private:
    void adjust() {
        while (lpq.size() > rpq.size() + 1) {
            rpq.push(lpq.top());
            lpq.pop();
        }
        
        while (lpq.size() < rpq.size()) {
            lpq.push(rpq.top());
            rpq.pop();
        }
    }
private:
    priority_queue<int, vector<int>, less<int> > lpq;
    priority_queue<int, vector<int>, greater<int> > rpq;
};
