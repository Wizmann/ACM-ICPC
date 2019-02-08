class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto iter = mp.find(key);
        if (iter == mp.end()) {
            return "";
        }
        const map<int, string>& mp2 = iter->second;
        if (mp2.empty()) {
            return "";
        }
        auto jter = mp2.upper_bound(timestamp);
        if (jter == mp2.begin()) {
            return "";
        }
        --jter;
        return jter->second;
    }
private:
    map<string, map<int, string> > mp;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
