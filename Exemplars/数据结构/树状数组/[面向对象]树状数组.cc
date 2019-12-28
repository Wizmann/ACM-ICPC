#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x


const int SIZE = 212345;

int lowbit(int x) { return x & (-x); }

template <typename T>
class BIT
{
public:
    BIT() {}
    BIT(int n_) : n(n_), nums(n + 1) {}

    void add(int x, T val) {
        while(x < n) {
            nums[x] += val;
            x += lowbit(x);
        }
    }

    T sum(int x) {
        T res = 0;
        while(x > 0) {
            res += nums[x];
            x -= lowbit(x);
        }
        return res;
    }

    T sum(int a, int b) {
        return sum(b) - sum(a - 1);
    }
private:
    int n;
    vector<T> nums;
};

template <typename T>
class SegBIT
{
public:
    SegBIT() {}
    SegBIT(int n_) : n(n_ + 1), nums(n + 1) {}

    void addseg(int a, int b, T val) {
        add(a - 1, -val);
        add(b, val);
    }

    T sum(int x) {
        T res=0;
        while(x < n) {
            res += nums[x];
            x += lowbit(x);
        }
        return res;
    }

    void add(int x, T val) {
        while (x > 0) {
            nums[x] += val;
            x -= lowbit(x);
        }
    }
private:
    int n;
    vector<T> nums;
};

template <typename T>
class SegSegBIT
{
public:
    SegSegBIT() {}
    SegSegBIT(int n_) : n(n_), A(n), B(n) {}
    
    void update(int pos, T val) {
        A.add(pos, val);
        B.add(pos, pos * val);
    }
    
    void addseg(int a, int b, T val) {
        update(b, val);
        if(a > 1) {
            update(a - 1, -val);
        }
    }

    T sum(int x) {
        if (x) {
            return A.sum(x) * x + B.sum(x - 1);
        } else {
            return 0;
        }
    }

    T sum(int a, int b) {
        return sum(b) - sum(a - 1);
    }
private:
    int n;
    SegBIT<T> A;
    BIT<T> B;
};

typedef long long llint;

int main() {
    int n;
    input(n);

    int size = 1;
    int cmd;
    int a, b;
    SegSegBIT<llint> bit(SIZE);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cmd);
        if (cmd == 1) {
            scanf("%d%d", &a, &b);
            bit.addseg(1, a, b);
        } else if (cmd == 2) {
            size += 1;
            scanf("%d", &a);
            bit.addseg(size, size, a);
        } else if (cmd == 3) {
            llint v = bit.sum(size, size);
            bit.addseg(size, size, -v);
            size -= 1;
        }
        llint tot = bit.sum(1, size);
        printf("%.8lf\n", 1.0 * tot / size);
    }
    return 0;
}
