class MinStack {
    public void push(int x) {
        _st.push(x);
        if (_min.empty() || x <= _min.peek()) {
            _min.push(x);
        }
    }

    public void pop() {
        int u = _st.pop();
        if (u == _min.peek()) {
            _min.pop();
        }
    }

    public int top() {
        return _st.peek();
    }

    public int getMin() {
        return _min.peek();
    }
    private Stack<Integer> _st  = new Stack<Integer>();
    private Stack<Integer> _min = new Stack<Integer>();
}
