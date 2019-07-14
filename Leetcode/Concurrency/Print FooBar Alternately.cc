class FooBar {
private:
    int n;

public:
    FooBar(int n) {
        this->n = n;
        this->state = 0;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(m);
            
            cv.wait(lock, [&]{ return state == 0; });
            
            state ^= 1;
            
            cv.notify_all();
            
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(m);
            
            cv.wait(lock, [&]{ return state == 1; });
            
            state ^= 1;
               
            cv.notify_all();
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
        }
    }
private:
    int state;
    std::condition_variable cv;
    std::mutex m;
};
