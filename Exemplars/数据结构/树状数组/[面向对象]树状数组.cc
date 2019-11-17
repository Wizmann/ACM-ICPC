#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

template <typename T>
class SegBITree
{
public:
    SegBITree() {}
    SegBITree(int n_) : n(n_ + 1), nums(n + 1) {}

    void addseg(int a, int b, T val)
    {
        _add(a-1,-val);
        _add(b,val);
    }

    T sum(int x)
    {
        T res=0;
        while(x < n)
        {
            res += nums[x];
            x += lowbit(x);
        }
        return res;
    }

private:
    void _add(int x, T val)
    {
        while (x > 0)
        {
            nums[x] += val;
            x -= lowbit(x);
        }
    }
private:
    int lowbit(int x) { return x & (-x); }

    int n;
    vector<T> nums;
};
