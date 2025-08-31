#include <bits/stdc++.h>
using namespace std;

class Solution {
    static constexpr int MAXV = 50000;                 // 最大值（含）——仅在此范围内可能为质数
    static vector<char> is_prime;                      // 0/1 表示
    static bool sieve_ready;

    static void build_sieve() {
        if (sieve_ready) return;
        is_prime.assign(MAXV + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * 1LL * i <= MAXV; ++i) {
            if (is_prime[i]) {
                for (int j = i * i; j <= MAXV; j += i) is_prime[j] = false;
            }
        }
        sieve_ready = true;
    }

    static inline bool isPrimeFast(int x) {
        return (0 <= x && x <= MAXV) && is_prime[x];
    }

public:
    int primeSubarray(vector<int>& nums, int k) {
        build_sieve();

        // 用“合数”作哨兵，避免改变窗口中质数的统计
        nums.push_back(0);                   // 0 一定不是质数
        const int n = (int)nums.size();

        int q1 = 0, q2 = 0;
        multiset<int> st1;                   // 窗口内质数（至多 2 个）
        multiset<int> st2;                   // 同上，用来维护 |max-min| <= k
        long long ans = 0;

        for (int p = 0; p < n; ++p) {
            // 扩张 q1：直到窗口里至少有 2 个质数（或到达数组末尾）
            while (q1 < n && (int)st1.size() < 2) {
                if (isPrimeFast(nums[q1])) st1.insert(nums[q1]);
                ++q1;
            }

            // 扩张 q2：直到放不下为止（质数数目<2 或者 max-min <= k）
            while (q2 < n &&
                   ( (int)st2.size() < 2 ||
                     (*st2.rbegin() - *st2.begin()) <= k )) {
                if (isPrimeFast(nums[q2])) st2.insert(nums[q2]);
                ++q2;
            }

            // 若当前从 p 开始的区间中已经包含至少 2 个质数，
            // 那么满足“至少两个质数且 max-min > k”的最小右端是 q1，
            // 满足“至多 k”的最大右端是 q2-1，于是可数的个数为 (q2 - q1)。
            if ((int)st1.size() >= 2) {
                ans += (q2 - q1);
            }

            // 左端点右移：如果 nums[p] 是质数，从两个 multiset 中各删一个
            if (isPrimeFast(nums[p])) {
                auto it1 = st1.find(nums[p]);
                if (it1 != st1.end()) st1.erase(it1);
                auto it2 = st2.find(nums[p]);
                if (it2 != st2.end()) st2.erase(it2);
            }
        }

        return (int)ans;
    }
};

// 静态成员定义
vector<char> Solution::is_prime;
bool Solution::sieve_ready = false;

//////////////

#include <bits/stdc++.h>
using namespace std;

class Solution {
    static constexpr int MAXV = 50000;  // 题意：最大质数不超过 5e4
    static vector<char> is_prime;
    static bool sieve_ready;

    static void build_sieve() {
        if (sieve_ready) return;
        is_prime.assign(MAXV + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; 1LL * i * i <= MAXV; ++i) {
            if (is_prime[i]) {
                for (int j = i * i; j <= MAXV; j += i) is_prime[j] = false;
            }
        }
        sieve_ready = true;
    }
    static inline bool isPrimeFast(int x) {
        return 0 <= x && x <= MAXV && is_prime[x];
    }

public:
    int primeSubarray(vector<int>& nums, int k) {
        build_sieve();

        nums.push_back(0);                 // 用合数作哨兵，避免干扰
        const int n = (int)nums.size();

        long long ans = 0;

        int q1 = 0, q2 = 0;
        int cnt1 = 0;                      // [p, q1) 内质数个数
        int cnt2 = 0;                      // [p, q2) 内质数个数
        deque<int> minq, maxq;             // 只存“质数下标”，分别维护递增/递减

        for (int p = 0; p < n; ++p) {
            // 扩张 q1：直到有至少两个质数
            while (q1 < n && cnt1 < 2) {
                if (isPrimeFast(nums[q1])) {
                    ++cnt1;
                }
                ++q1;
            }

            auto delta = [&]() {
                int cur_min = nums[minq.front()];
                int cur_max = nums[maxq.front()];
                return cur_max - cur_min;
            };

            // 扩张 q2：直到违反条件（当质数≥2时需要 max-min <= k）
            while (q2 < n && (cnt2 < 2 || delta() <= k)) {
                if (isPrimeFast(nums[q2])) {
                    // 维护 minq（值递增）
                    while (!minq.empty() && nums[minq.back()] >= nums[q2]) minq.pop_back();
                    minq.push_back(q2);
                    // 维护 maxq（值递减）
                    while (!maxq.empty() && nums[maxq.back()] <= nums[q2]) maxq.pop_back();
                    maxq.push_back(q2);
                    ++cnt2;
                }
                ++q2;
            }
            // cout << p << ' ' << q1 << ' ' << q2 << ' ' << cnt1 << ' ' << cnt2 << endl;
            if (cnt1 >= 2) ans += (q2 - q1);

            // 左端右移：把 nums[p] 移出两个窗口
            if (isPrimeFast(nums[p])) {
                // 更新 cnt1/cnt2
                --cnt1;
                --cnt2;
                // 过期掉队首
                if (!minq.empty() && minq.front() == p) minq.pop_front();
                if (!maxq.empty() && maxq.front() == p) maxq.pop_front();
            }
        }

        return (int)ans;
    }
};

// 静态成员定义
vector<char> Solution::is_prime;
bool Solution::sieve_ready = false;
