class Solution {
public:
    using ll = long long;

    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        // ----------------- 第一步：统计所有不递减的连续段 -----------------
        // groups: 每个元素是 [L, R] 表示一个最大的不递减段
        vector<pair<int,int>> groups;
        vector<ll> groupVal; // 每一段里 stable 子数组的数量（= len * (len+1) / 2）

        int pre = 0;  // 当前段起点
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                // 在 i-1 和 i 之间出现断点，前一段结束
                int L = pre;
                int R = i - 1;
                int len = R - L + 1;
                groups.push_back({L, R});
                groupVal.push_back(1LL * len * (len + 1) / 2);
                pre = i; // 新的一段从 i 开始
            }
        }
        // 最后一段
        {
            int L = pre;
            int R = n - 1;
            int len = R - L + 1;
            groups.push_back({L, R});
            groupVal.push_back(1LL * len * (len + 1) / 2);
        }

        int g = groups.size();

        // 前缀和，相当于对每个段做“记忆化 / DP”
        // prefix[i] = 前 i 个段（0..i-1）的 stable 子数组总数
        vector<ll> prefix(g + 1, 0);
        for (int i = 0; i < g; ++i) {
            prefix[i + 1] = prefix[i] + groupVal[i];
        }

        // 单独拿出所有段的起点，方便二分
        vector<int> starts(g);
        for (int i = 0; i < g; ++i) {
            starts[i] = groups[i].first;
        }

        // ----------------- 第二步：查询函数（用“记忆化”合并区间） -----------------
        auto queryOne = [&](int l, int r) -> ll {
            // 找到包含 l 的那一段的下标 lb：满足 groups[lb].first <= l 的最大 lb
            int lb = int(upper_bound(starts.begin(), starts.end(), l) - starts.begin()) - 1;
            // 找到包含 r 的那一段的下标 rb：满足 groups[rb].first <= r 的最大 rb
            int rb = int(upper_bound(starts.begin(), starts.end(), r) - starts.begin()) - 1;

            // 理论上 l, r 都在 [0, n-1]，且第一段一定从 0 开始，所以 lb, rb >= 0
            // 保险起见加个判断：
            if (lb < 0 || rb < 0) {
                ll len = r - l + 1;
                return len * (len + 1) / 2;
            }

            // 如果 l, r 落在同一段（或者 lb >= rb，不会跨越真正的断点）
            if (lb >= rb) {
                ll len = r - l + 1;
                return len * (len + 1) / 2;
            }

            // 中间完整覆盖的整段（不需要裁剪），用前缀和直接拿
            ll mid = prefix[rb] - prefix[lb + 1];

            // 左侧被裁剪的段：从 l 到 groups[lb].second
            ll leftLen = 1LL * (groups[lb].second - l + 1);
            ll leftCnt = leftLen * (leftLen + 1) / 2;

            // 右侧被裁剪的段：从 groups[rb].first 到 r
            ll rightLen = 1LL * (r - groups[rb].first + 1);
            ll rightCnt = rightLen * (rightLen + 1) / 2;

            return mid + leftCnt + rightCnt;
        };

        // 逐个处理查询
        vector<ll> ans;
        ans.reserve(queries.size());
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            ans.push_back(queryOne(l, r));
        }
        return ans;
    }
};
