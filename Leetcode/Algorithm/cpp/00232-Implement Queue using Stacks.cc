class Queue {
public:
    Queue(): ptr(0) {}
    // Push element x to the back of queue.
    void push(int x) {
        st[ptr].push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        adjust();
        st[ptr^1].pop();
    }

    // Get the front element.
    int peek(void) {
        adjust();
        return st[ptr^1].top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return st[0].empty() && st[1].empty();
    }
private:
    void adjust() {
        if (st[ptr^1].empty()) {
            int n = st[ptr].size();
            for (int i = 0; i < n; i++) {
                st[ptr^1].push(st[ptr].top());
                st[ptr].pop();
            }
        }
    }
private:
    stack<int> st[2];
    int ptr;
};
