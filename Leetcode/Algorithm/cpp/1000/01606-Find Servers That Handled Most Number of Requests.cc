class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> res;
        
        set<int> servers;
        for (int i = 0; i < k; i++) {
            servers.insert(i);
        }
        
        const int m = arrival.size();
        vector<pair<int, int> > events;
        for (int i = 0; i < m; i++) {
            int idx = i + 1;
            events.push_back({arrival[i], idx});
            events.push_back({arrival[i] + load[i], -idx});
        }
        sort(events.begin(), events.end());
        vector<int> count(k, 0);
        vector<int> serve(m, -1);
        
        for (const auto& event : events) {
            auto t = event.first;
            int idx = event.second;
            
            if (idx > 0) {
                idx -= 1;
                if (servers.empty()) {
                    continue;
                } else {
                    auto iter = servers.lower_bound(idx % k);
                    if (iter == servers.end()) {
                        iter = servers.lower_bound(0);
                    }
                    serve[idx] = *iter;
                    count[*iter]++;
                    servers.erase(iter);
                }
            } else {
                idx = -idx;
                idx -= 1;
                assert(idx >= 0);
                int s = serve[idx];
                if (s >= 0) {
                    servers.insert(s);
                }
            }
        }
        
        int maxi = *max_element(count.begin(), count.end());
        
        for (int i = 0; i < k; i++) {
            if (count[i] == maxi) {
                res.push_back(i);
            }
        }
        return res;
    }
};
