class FizzBuzz {
private:
    int n;

public:
    FizzBuzz(int n) {
        this->n = n;
        counter = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (counter <= n) {
            std::unique_lock<std::mutex> lk(m);
            cv.wait(lk, [&] {
                return counter > n || (counter % 3 == 0 && counter % 5 != 0);
            });
            if (counter <= n) {
                printFizz();
            }
            counter++;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (counter <= n) {
            std::unique_lock<std::mutex> lk(m);
            cv.wait(lk, [&] { 
                return counter > n || (counter % 5 == 0 && counter % 3 != 0);
            });
            if (counter <= n) {
                printBuzz();
            }
            counter++;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (counter <= n) {
            std::unique_lock<std::mutex> lk(m);
            cv.wait(lk, [&] { 
                return counter > n || (counter % 5 == 0 && counter % 3 == 0);
            });
            if (counter <= n) {
                printFizzBuzz();
            }
            counter++;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (counter <= n) {
            std::unique_lock<std::mutex> lk(m);
            cv.wait(lk, [&] { 
                return counter > n || (counter % 5 != 0 && counter % 3 != 0);
            });
            if (counter <= n) {
                printNumber(counter);
            }
            counter++;
            cv.notify_all();
        }
    }
private:
    int counter;
    std::mutex m;
    std::condition_variable cv;
};
