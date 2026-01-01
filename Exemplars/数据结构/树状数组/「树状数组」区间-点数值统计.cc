const int N = 55555;

inline int lowbit(int x)
{
    return x&(-x);
}

class BITree { // 点更新，区间查询
public:
    BITree() {}
    BITree(int n_): n(n_), tree(n + 1, 0) {}

    void add(int pos, int val) {
        while (pos < n) {
            tree[pos] += val;
            pos += lowbit(pos);
        }
    }

    int sum(int pos) {
        int res = 0;
        while (pos > 0) {
            res += tree[pos];
            pos -= lowbit(pos);
        }
        return res;
    }

    int sum(int a ,int b) {
        return sum(b) - sum(a - 1);
    }
private:
    int n;
    vector<int> tree;
};

class SegBIT { // 区间更新，点查询
public:
    SegBIT() {}
    SegBIT(int n_): n(n_), tree(n + 1, 0) {}

    void add(int pos, int val) {
        while (pos > 0) {
            tree[pos] += val;
            pos -= lowbit(pos);
        }
    }

    void addseg(int a, int b, int val) {
        add(a - 1, -val);
        add(b, val);
    }

    //点查询
    int sum(int pos) {
        int res = 0;
        while (pos < n) {
            res += tree[pos];
            pos += lowbit(pos);
        }
        return res;
    }
private:
    int n;
    vector<int> tree;
};

class SegSegBIT { // 区间更新，区间查询
public:
    SegSegBIT(int n_) : n(n_), A(n), B(n) {}
    
    void addseg(int a, int b, int val) { // 区间更新
        update(b, val);
        if (a > 1) {
            update(a - 1, -val);
        }
    }

    int sum(int x) {
        if (x) {
            return A.sum(x) * x + B.sum(x - 1);
        } else {
            return 0;
        }
    }

    int sum(int a, int b) { //区间查询
        return sum(b) - sum(a - 1);
    }
private:
    void update(int pos, int val) {
        A.add(pos,val);
        B.add(pos,pos*val);
    }

    int n;
    SegBIT A;
    BITree B;
};
