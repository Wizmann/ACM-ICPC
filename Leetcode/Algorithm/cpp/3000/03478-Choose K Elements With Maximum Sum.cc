typedef long long llint;

struct Item {
    int key;
    int value;
    int index;
};

class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        const int n = nums1.size();
        multiset<int> st1;
        vector<Item> items;
        for (int i = 0; i < n; i++) {
            items.push_back({nums1[i], nums2[i], i});
        }
        sort(items.begin(), items.end(), [](const Item& i1, const Item& i2) {
            return i1.key < i2.key;
        });

        vector<llint> res(n, 0);
        llint tot = 0;
        int pre = -1;
        int pre_index = -1;

        for (const auto& item : items) {
            if (item.key == pre) {
                res[item.index] = res[pre_index];
            } else {
                res[item.index] = tot;
            }
            st1.insert(item.value);
            tot += item.value;
            while (st1.size() > k) {
                tot -= *st1.begin();
                st1.erase(st1.begin());
            }
            pre = item.key;
            pre_index = item.index;
        }
        return res;
    }
};
