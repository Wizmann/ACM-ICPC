class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // pass
    }

    void push(int element) {
        stack1.push(element);
    }
    
    int pop() {
        if (stack2.empty()) {
            do_maintain();
        }
        int res = stack2.top();
        stack2.pop();
        return res;
    }

    int top() {
        if (stack2.empty()) {
            do_maintain();
        }
        return stack2.top();
    }
private:
    void do_maintain() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
};

