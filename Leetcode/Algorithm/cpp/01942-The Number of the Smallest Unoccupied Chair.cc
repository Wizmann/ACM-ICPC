class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        set<int> rem;
        int base = -1;
        vector<pair<int, int> > events;
        const int m = times.size();
        for (int i = 1; i <= m; i++) {
            int arr = times[i - 1][0];
            int leave = times[i - 1][1];
            events.push_back({arr, +i});
            events.push_back({leave, -i});
        }
        sort(events.begin(), events.end());
        vector<int> seats(m + 1, -1);
        
        for (auto& e : events) {
            if (e.second > 0) {
                if (rem.empty()) {
                    seats[e.second] = ++base;
                } else {
                    seats[e.second] = *rem.begin();
                    rem.erase(rem.begin());
                }
            } else {
                rem.insert(seats[-e.second]);
            }
        }
        
        return seats[targetFriend + 1];
    }
};
