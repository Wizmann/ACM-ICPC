class ZeroEvenOdd {
private:
    int n;
    int state;
    std::condition_variable cv;
    std::mutex m;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->state = 0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(m);

            cv.wait(lock, [&]{ return state % 2 == 0; });

            state++;

            cv.notify_all();

            printNumber(0);
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            std::unique_lock<std::mutex> lock(m);

            cv.wait(lock, [&]{ return (state + 1) / 2 == i; });

            state++;

            cv.notify_all();
            cout << (state + 1) / 2 << endl;
            printNumber((state + 1) / 2);
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            std::unique_lock<std::mutex> lock(m);

            cv.wait(lock, [&]{ return (state + 1) / 2 == i; });

            state++;

            cv.notify_all();          
            cout << (state + 1) / 2 << endl;
            printNumber((state + 1) / 2);
        }
    }
};
