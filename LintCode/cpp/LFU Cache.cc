#include <list>

class LFUCache {
public:
    /*
    * @param capacity: An integer
    */LFUCache(int capacity_) {
        size = 0;
        capacity = capacity_;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        cout << "set: " << key << ' ' << value << endl;
        if (values.count(key) == 0) {
            size++;
            erase_least_freq();
            freqs[1].push_back({key, value, 1});
            values[key] = --freqs[1].end();
        } else {
            values[key]->value = value;
            freq_plus(key);
        }
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        cout << "get: " << key << endl;
        if (values.count(key) != 0) {
            freq_plus(key);
            return values[key]->value;
        }
        return -1;
    }
    
    void erase_least_freq() {
        if (size <= capacity) {
            return;
        }
        
        auto key = freqs.begin()->second.begin()->key;
        cout << "least freq: " << key << endl;
        values.erase(values.find(key));
        freqs.begin()->second.pop_front();
        if (freqs.begin()->second.empty()) {
            freqs.erase(freqs.begin());
        }
        
        size--;
    }
    
    void freq_plus(int key) {
        auto iter = values[key];
        int freq = iter->freq;
        int value = iter->value;
        
        freqs[freq].erase(iter);
        
        if (freqs[freq].empty()) {
            freqs.erase(freqs.find(freq));
        }
        
        freqs[freq + 1].push_back({key, value, freq + 1});
        values[key] = --freqs[freq + 1].end();
    }
    
private:
    struct LFUNode {
        int key, value, freq;
    };

    int size;
    int capacity;
    map<int, list<LFUNode> > freqs;
    map<int, list<LFUNode>::iterator> values;
};
