class LRUCache{
public:
    struct Entry {
        int key, value;
        Entry(){}
        Entry(int ikey, int ivalue): key(ikey), value(ivalue) {}
    };

    LRUCache(int icap): capacity(icap) {}
    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        int res = mp[key] -> value;
        move_front(key);
        return res;
    }

    void set(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key] -> value = value;
            move_front(key);
        } else {
            Entry res(key, value);
            if (lst.size() >= capacity) {
                pop_back();
            }
            lst.push_front(res);
            mp[key] = lst.begin();
        }
    }
    
private:
    map<int, list<Entry>::iterator> mp;
    list<Entry> lst;
    int capacity;
    
    void move_front(int key) {
        //ASSERT_NE(mp.find(key), mp.end())
        Entry e = *mp[key];
        auto iter = mp[key];
        lst.erase(iter);
        lst.push_front(e);
        mp[key] = lst.begin();
    }
    
    void pop_back() {
        Entry e = *(--lst.end());
        mp.erase(e.key);
        lst.pop_back();
    }
};
