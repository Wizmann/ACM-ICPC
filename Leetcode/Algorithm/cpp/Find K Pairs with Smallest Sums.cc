vector<int> nums1;
vector<int> nums2;

struct Pointer {
public:
    Pointer(int p1_, int p2_): p1(p1_), p2(p2_) {
        // pass    
    }

    bool operator < (const Pointer& other) const {
        return value() > other.value();
    }

    const int value() const {
        return nums1[p1] + nums2[p2];
    }

    vector<Pointer> move() {
        vector<Pointer> pointers;
        if (p1 + 1 < nums1.size()) {
            auto pp = *this;
            pp.p1++;
            pointers.push_back(pp);
        }

        if (p2 + 1 < nums2.size()) {
            auto pp = *this;
            pp.p2++;
            pointers.push_back(pp);
        }
        return pointers;
    }

    const int value1 () const {
        return nums1[p1];
    }

    const int value2() const {
        return nums2[p2];
    }

    int p1;
    int p2;
};

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(
            vector<int>& nums1_, vector<int>& nums2_, int k) {
        nums1 = nums1_;
        nums2 = nums2_;

        priority_queue<Pointer> pq;
        pq.push(Pointer(0, 0));
        vector<pair<int, int> > res;

        set<pair<int, int> > visit;

        if (nums1.empty() || nums2.empty()) {
            return res;
        }

        while (res.size() < k && !pq.empty()) {
            auto p = pq.top();
            pq.pop();

            if (visit.count({p.p1, p.p2}) != 0) {
                continue;
            }
            visit.insert({p.p1, p.p2});

            res.push_back({p.value1(), p.value2()});

            for (auto next: p.move()) {
                pq.push(next);
            }
        }
        return res;
    }
};
