class Semaphore {
public:
  Semaphore(int count = 0) : count_(count) {
  }
    
  void Set(int count){
      count_ = count;
  }
    
  void Signal() {
    std::unique_lock<std::mutex> lock(mutex_);
    ++count_;
    cv_.notify_one();
  }

  void Wait() {
    std::unique_lock<std::mutex> lock(mutex_);
    while(count_ <= 0){
        cv_.wait(lock);
    }
    --count_;
  }

private:
  std::mutex mutex_;
  std::condition_variable cv_;
  int count_;
};

class DiningPhilosophers {
public:
    DiningPhilosophers() {
        sem.Set(4);
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        sem.Wait();
        
        int first = philosopher;
        int second = (philosopher + 1) % 5;
        
        assert(0 <= first && first < 5);
        assert(0 <= second && second < 5);
        
        if (philosopher == 0) {
            swap(first, second);
        }

        std::scoped_lock lk1(lock[first]);
        std::scoped_lock lk2(lock[second]);

        pickLeftFork();
        pickRightFork();
        eat(); 
        putLeftFork();
        putRightFork();
        
        sem.Signal();
    }
private:
    std::mutex lock[5];
    Semaphore sem;
};
