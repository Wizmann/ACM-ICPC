class LRUCache{
public:
    LRUCache(int capacity) {
        _map.clear();
        _list.clear();
        _cap = capacity;
    }
    
    int get(int key) {
        if (_map.find(key) == _map.end()) {
            return -1;
        }
        int value = _map[key]->second;
        erase(key);
        set(key, value);
        return value;
    }
    
    void set(int key, int value) {
        if (_map.find(key) == _map.end()) {
            if (_map.size() >= _cap) {
                erase_last();
            }
        } else {
            erase(key);
        }
        _list.push_front({key, value});
        _map[key] = _list.begin();
    }
private:
    void erase(int key) {
        auto iter = _map[key];
        _list.erase(iter);
        _map.erase(_map.find(key));
    }
    void erase_last() {
        int key = _list.rbegin()->first;
        erase(key);
    }
private:
    unordered_map<int, list<pair<int, int> >::iterator> _map;
    list<pair<int, int> > _list;
    int _cap;
};
