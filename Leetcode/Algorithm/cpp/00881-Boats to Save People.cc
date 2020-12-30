class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int p = 0;
        int q = people.size() - 1;
        int ans = 0;
        while (p <= q) {
            if (p < q && people[p] + people[q] <= limit) {
                p++;
            }
            q--;
            ans++;
        }
        return ans;
    }
};
