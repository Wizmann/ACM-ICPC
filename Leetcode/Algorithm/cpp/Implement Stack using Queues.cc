class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q[ptr].push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while (q[ptr].size() > 1) {
            q[ptr^1].push(q[ptr].front());
            q[ptr].pop();
        }
        q[ptr].pop();
        ptr ^= 1;
    }

    // Get the top element.
    int top() {
        int v = 0;
        while (!q[ptr].empty()) {
            v = q[ptr].front();
            q[ptr^1].push(v);
            q[ptr].pop();
        }
        ptr ^= 1;
        return v;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q[0].empty() && q[1].empty();
    }
private:
    int ptr = 0;
    queue<int> q[2];
};
