class NumberContainers {
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        int pre = -1;
        if (mp1.count(index)) {
            pre = mp1[index];
        }
        if (number == pre) {
            return;
        }
        mp1[index] = number;
        mp2[number].insert(index);
        if (pre != -1) {
            mp2[pre].erase(mp2[pre].find(index));
        }
    }
    
    int find(int number) {
        if (mp2[number].empty()) {
            return -1;
        }
        return *mp2[number].begin();
    }
private:
    map<int, int> mp1;
    map<int, set<int> > mp2;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
