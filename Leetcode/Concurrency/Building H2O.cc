class H2O {
public:
    H2O() {
        r = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lk(m);

        while ((r & 3) == 3) {
            cv.wait(lk);
        }
        
        if ((r & 1) == 0) {
            r |= 1;
        } else if ((r & 2) == 0) {
            r |= 2;
        }
        
        if (r == 7) {
            r = 0;
        }
        cv.notify_one();
        
        releaseHydrogen();
    }

    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lk(m);

        while ((r & 4) == 4) {
            cv.wait(lk);
        }
        
        r |= 4;
        
        if (r == 7) {
            r = 0;
        }

        cv.notify_one();
        
        releaseOxygen();
    }
private:
     int r;
     std::mutex m;
     std::condition_variable cv;
};
