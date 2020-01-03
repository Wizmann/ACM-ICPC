template<typename T>
class FuzzyMap {
public:
    FuzzyMap() {
        // pass
    }
    
    template<typename iterT>
    FuzzyMap(iterT st, iterT end) {
        for (auto iter = st; iter != end; ++iter) {
            add_value(*iter, +1);
        }
    }

    void set_value(const T& t, int value) {
        mp[t] = value;
        pq.push({value, t});
    }
    
    void add_value(const T& t, int delta) {
        mp[t] += delta;
        pq.push({mp[t], t});
    }
    
    int get_value(const T& t) {
        return mp[t];
    }
    
    int get_max(T& t, int& value) {
        while (!pq.empty()) {
            const auto& cur = pq.top();

            const int& cnt = cur.first;
            const T& item = cur.second;
            
            if (mp[item] != cnt) {
                pq.pop();
            } else {
                t = item;
                value = cnt;
                return 0;
            }
        }
        return -1;
    }
private:
    map<T, int> mp;
    priority_queue<pair<int, T> > pq;
};
