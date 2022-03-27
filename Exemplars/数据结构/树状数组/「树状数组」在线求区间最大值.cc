struct BiTreeRMQ
{
    int baum[SIZE],num[SIZE];
    inline int lowbit(int x)
    {
        return x&(-x);
    }
    void init()
    {
        for(int i=1;i<SIZE;i++)
        {
            baum[i]=num[i];
            for(int j=1;j<lowbit(i);j<<=1)
            {
                baum[i]=min(baum[i],baum[i-j]);
            }
        }
    }
    int query(int a,int b)
    {
        int ans=num[b];
        while(a != b)
        {
            for (b = b - 1; b - lowbit(b) >= a; b -= lowbit(b))
            {
                ans=min(ans,baum[b]);
            }
            ans = min(ans, num[b]);
        }
        return ans;
    }

    void modify(int pos,int val)
    {
        num[pos]=val;
        for(int i=pos;i<SIZE;i+=lowbit(i))
        {
            baum[i]=num[i];
            for(int j=1;j<lowbit(i);j<<=1)
            {
                baum[i]=min(baum[i],baum[i-j]);
            }
        }
    }
};


///////

// 模板没验过

template <typename T, class Compare=less<int> >
class BITreeRMQ {
public:
    BITreeRMQ() {}
    BITreeRMQ(int n_, const vector<T>& nums_) : n(n_), nums(nums_), tree(nums_) {
        assert(nums.size() == n);
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < lowbit(i); j <<= 1) {
                tree[i] = cmp(tree[i], tree[i - j]);
            }
        }
    }

    T query(int a, int b) {
        T ans = nums[b];
        while (a != b) {
            for (b = b - 1; b - lowbit(b) >= a; b -= lowbit(b)) {
                ans = cmp(ans, tree[b]);
            }
            ans = cmp(ans, nums[b]);
        }
        return ans;
    }

    void modify(int pos, T val) {
        nums[pos] = val;
        for (int i = pos; i < n; i += lowbit(i)) {
            tree[i] = nums[i];
            for (int j = 1; j < lowbit(i); j <<= 1) {
                tree[i] = cmp(tree[i], tree[i - j]);
            }
        }
    }
private:
    T cmp(T a, T b) {
        return cmp_func(a, b)? a: b;
    }

    inline int lowbit(int x) {
        return x&(-x);
    }

    vector<T> tree;
    vector<T> nums;
    Compare cmp_func = Compare();
    int n;
};
