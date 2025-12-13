// Balanced Tree Implementation

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// ordered set with order statistics
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = (int)nums.size();
        vector<long long> pref(n);

        // map to +1 / -1 and build prefix sums
        for (int i = 0; i < n; i++) {
            long long v = (nums[i] == target) ? 1 : -1;
            pref[i] = v + (i ? pref[i - 1] : 0LL);
        }

        // Use (value, index) to support duplicates
        ordered_set<pair<long long,int>> os;
        for (int i = 0; i < n; i++) os.insert({pref[i], i});

        long long ans = 0;
        for (int l = 0; l < n; l++) {
            long long pre = (l == 0) ? 0LL : pref[l - 1];

            // count of elements with value <= pre:
            // order_of_key({pre+1, -INF}) == count of pairs with (value < pre+1),
            // which is exactly value <= pre regardless of index
            long long le = os.order_of_key({pre + 1, INT_MIN});

            // count with value > pre
            ans += (long long)os.size() - le;

            // move l forward: remove pref[l] so remaining are r >= l+1 next round
            os.erase({pref[l], l});
        }

        return ans;
    }
};


// ScapegoatTree Implementation

#include <bits/stdc++.h>
using namespace std;

struct ScapegoatTree {
    static constexpr double ALPHA = 0.70;

    struct Key {
        long long v;
        int id;
        bool operator<(Key const& o) const {
            if (v != o.v) return v < o.v;
            return id < o.id;
        }
        bool operator==(Key const& o) const {
            return v == o.v && id == o.id;
        }
    };

    struct Node {
        Key key;
        Node *l = nullptr, *r = nullptr;
        int sz = 1;        // total nodes (incl deleted)
        int live = 1;      // non-deleted nodes
        bool del = false;  // lazy delete
        Node(const Key& k) : key(k) {}
    };

    Node* root = nullptr;
    int liveAll = 0;
    int szAll = 0;

    static int S(Node* t) { return t ? t->sz : 0; }
    static int L(Node* t) { return t ? t->live : 0; }

    static void pull(Node* t) {
        if (!t) return;
        t->sz = 1 + S(t->l) + S(t->r);
        t->live = (t->del ? 0 : 1) + L(t->l) + L(t->r);
    }

    static bool bad(Node* t) {
        if (!t) return false;
        int ls = S(t->l), rs = S(t->r);
        return (ls > (int)(ALPHA * t->sz) || rs > (int)(ALPHA * t->sz));
    }

    static void collectLive(Node* t, vector<Node*>& a) {
        if (!t) return;
        collectLive(t->l, a);
        if (!t->del) a.push_back(t);
        collectLive(t->r, a);
    }

    static Node* buildBalanced(vector<Node*>& a, int lo, int hi) {
        if (lo > hi) return nullptr;
        int mid = (lo + hi) >> 1;
        Node* t = a[mid];
        t->l = buildBalanced(a, lo, mid - 1);
        t->r = buildBalanced(a, mid + 1, hi);
        t->del = false;
        pull(t);
        return t;
    }

    static Node* rebuild(Node* t) {
        vector<Node*> a;
        a.reserve(L(t));
        collectLive(t, a);
        return buildBalanced(a, 0, (int)a.size() - 1);
    }

    void insert(const Key& key) {
        vector<Node**> path;
        Node** cur = &root;
        int depth = 0;

        while (*cur) {
            path.push_back(cur);
            if (key < (*cur)->key) cur = &((*cur)->l);
            else cur = &((*cur)->r);
            depth++;
        }

        *cur = new Node(key);
        path.push_back(cur);

        for (int i = (int)path.size() - 2; i >= 0; --i) pull(*path[i]);

        liveAll++;
        szAll++;

        int limit = (int)floor(log((double)szAll) / log(1.0 / ALPHA)) + 1;
        if (depth <= limit) return;

        for (int i = (int)path.size() - 2; i >= 0; --i) {
            Node* t = *path[i];
            if (bad(t)) {
                *path[i] = rebuild(t);
                for (int j = i - 1; j >= 0; --j) pull(*path[j]);
                break;
            }
        }
    }

    // erase exact Key (unique) — single path
    static bool eraseOne(Node* t, const Key& key) {
        if (!t) return false;
        if (key < t->key) {
            bool ok = eraseOne(t->l, key);
            if (ok) pull(t);
            return ok;
        }
        if (t->key < key) {
            bool ok = eraseOne(t->r, key);
            if (ok) pull(t);
            return ok;
        }
        // equal
        if (!t->del) {
            t->del = true;
            pull(t);
            return true;
        }
        return false;
    }

    bool erase(const Key& key) {
        bool ok = eraseOne(root, key);
        if (!ok) return false;
        liveAll--;

        if (liveAll < (int)(ALPHA * szAll)) {
            root = root ? rebuild(root) : nullptr;
            szAll = liveAll = L(root);
        }
        return true;
    }

    // count of live keys <= x
    int countLE(const Key& x) const {
        Node* cur = root;
        int ans = 0;
        while (cur) {
            if (x < cur->key) {
                cur = cur->l;
            } else {
                ans += L(cur->l);
                if (!cur->del) ans += 1;
                cur = cur->r;
            }
        }
        return ans;
    }

    int countAll() const { return liveAll; }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = (int)nums.size();
        vector<long long> pref(n);

        for (int i = 0; i < n; i++) {
            long long v = (nums[i] == target) ? 1 : -1;
            pref[i] = v + (i ? pref[i - 1] : 0LL);
        }

        ScapegoatTree sg;

        // Put all (pref[i], i) into the tree (unique)
        for (int i = 0; i < n; i++) {
            sg.insert({pref[i], i});
        }

        long long ans = 0;
        for (int l = 0; l < n; l++) {
            long long pre = (l == 0) ? 0LL : pref[l - 1];

            // count <= (pre, +INF)  => all with value <= pre
            int le = sg.countLE({pre, INT_MAX});
            ans += (long long)sg.countAll() - le;

            // remove exactly (pref[l], l)
            sg.erase({pref[l], l});
        }
        return ans;
    }
};
