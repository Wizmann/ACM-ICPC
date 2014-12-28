class MinStack {
public:
    static const int ERROR = 0x3f3f3f3f;
public:
    MinStack() {
        _st  = stack<int>();
        _min = stack<int>();
    }

    void push(int number) {
        _st.push(number);
        if (_min.empty() || _min.top() >= number) {
            _min.push(number);
        }
    }

    int pop() {
        if (_st.empty()) {
            return ERROR;
        }
        int num = _st.top();
        _st.pop();
        if (num == _min.top()) {
            _min.pop();
        }
        return num;
    }

    int min() {
        if (_min.empty()) {
            return ERROR;
        }
        return _min.top();
    }
private:
    stack<int> _st;
    stack<int> _min;
};

