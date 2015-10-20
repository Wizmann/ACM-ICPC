class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if (_left_heap.empty() && _right_heap.empty()) {
            _left_heap.push(num);
            return;
        }
        if (num > _left_heap.top()) {
            _right_heap.push(num);
        } else {
            _left_heap.push(num);
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        do_adjust();
        auto l_size = _left_heap.size();
        auto r_size = _right_heap.size();
        
        if ((l_size + r_size) % 2 == 0) {
            return (_left_heap.top() + _right_heap.top()) / 2.0;
        } else {
            return _left_heap.top();
        }
    }
private:
    void do_adjust() {
        while (_left_heap.size() > _right_heap.size()) {
            _right_heap.push(_left_heap.top());
            _left_heap.pop();
        }
        while (_left_heap.size() < _right_heap.size()) {
            _left_heap.push(_right_heap.top());
            _right_heap.pop();
        }
    }
private:
    typedef priority_queue<int, vector<int>, greater<int> > MinHeap;
    typedef priority_queue<int, vector<int>, less<int> >    MaxHeap;
private:
    MinHeap _right_heap;
    MaxHeap _left_heap;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
