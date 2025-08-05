class MapHeap {
public:
    MapHeap() {
        // pass
    }

    void push(string key, int value) {
        auto iter = _heap.insert({value, key});
        _mp[key] = iter;
    }

    int pop(string key) {
        auto mpiter = _mp.find(key);
        if (mpiter == _mp.end()) {
            return 0;
        }
        auto heapiter = mpiter->second;
        int res = heapiter->first;
        _heap.erase(heapiter);
        _mp.erase(mpiter);
        return res;
    }

    bool exist(string key) {
        auto mpiter = _mp.find(key);
        return mpiter != _mp.end();
    }
    
    bool empty() {
        return _heap.empty();
    }

    int get_max(string& key, int& value) {
        value = _heap.rbegin()->first;
        key = _heap.rbegin()->second;
        return 0;
    }

    int get_min(string& key, int& value) {
        value = _heap.begin()->first;
        key = _heap.begin()->second;
        return 0;
    }
private:
    multimap<int, string> _heap;
    unordered_map<string, decltype(_heap)::iterator > _mp;
};

class AllOne {
public:
    AllOne() {
        // pass
    }
    
    void inc(string key) {
        int value = mh.pop(key);
        mh.push(key, value + 1);
    }
    
    void dec(string key) {
        if (!mh.exist(key)) {
            return;
        }
        int value = mh.pop(key);
        if (value == 1) {
            return;
        }
        mh.push(key, value - 1);
    }
    
    string getMaxKey() {
        if (mh.empty()) {
            return "";
        }
        string key;
        int value;
        mh.get_max(key, value);
        return key;
    }
    
    string getMinKey() {
        if (mh.empty()) {
            return "";
        }
        string key;
        int value;
        mh.get_min(key, value);
        return key;
    }
private:
    MapHeap mh;
};
