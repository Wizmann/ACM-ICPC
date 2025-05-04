const int SECTION = 555;
const int SIZE = SECTION * SECTION;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        const int n = fruits.size();

        vector<multiset<int>> st(SECTION);

        for (int i = 0; i < n; i++) {
            int basket = baskets[i];
            st[i / SECTION].insert(basket);
        }

        int res = 0;
        for (auto fruit : fruits) {
            bool found = false;
            for (int i = 0; i < SECTION && !found; i++) {
                if (st[i].empty() || st[i].lower_bound(fruit) == st[i].end()) {
                    continue;
                }
                for (int j = i * SECTION; j < (i + 1) * SECTION; j++) {
                    if (baskets[j] >= fruit) {
                        // std::cout << fruit << ' ' << baskets[j] << endl;
                        st[i].erase(st[i].find(baskets[j]));
                        baskets[j] = -1;
                        found = true;
                        break;
                    }
                }
            }
            if (!found) {
                res++;
            }
        }
        return res;
    }
};
