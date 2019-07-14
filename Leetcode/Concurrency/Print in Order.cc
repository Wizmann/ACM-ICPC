class Foo {
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        std::unique_lock<std::mutex> lock(m);
        
        cv.wait(lock, [&]{ return state == 0; });
        
        state = (state + 1) % 3;
        cv.notify_all();
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lock(m);
        
        cv.wait(lock, [&]{ return state == 1; });
        
        state = (state + 1) % 3;
        cv.notify_all();
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lock(m);
        
        cv.wait(lock, [&]{ return state == 2; });
        
        state = (state + 1) % 3;
        cv.notify_all();
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
private:
    int state = 0;
    std::mutex m;
    std::condition_variable cv;
};
