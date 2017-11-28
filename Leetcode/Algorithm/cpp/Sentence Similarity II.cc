const int N = 2222;

class DisjointSet {
public:
    DisjointSet(int size_): size(size_), father(size_) {
        for (int i = 0; i < size_; i++) {
            father[i] = i;
        }
    }
    
    void make_union(int a, int b) {
        father[get_father(a)] = get_father(b);
    }
    
    int get_father(int x) {
        if (father[x] == x) {
            return x;
        }
        return father[x] = get_father(father[x]);
    }
private:
    int size;
    vector<int> father;
};

class Solution {
public:
    Solution(): idx(0), ds(N * 4) {
        // pass
    }
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        for (const auto& p: pairs) {
            int a = get_word_id(p.first);
            int b = get_word_id(p.second);
            ds.make_union(a, b);
        }
        
        int n = words1.size();
        int m = words2.size();
        if (n != m) {
            return false;
        }
        
        for (int i = 0; i < n; i++) {
            int a = get_word_id(words1[i]);
            int b = get_word_id(words2[i]);
            
            if (ds.get_father(a) != ds.get_father(b)) {
                cout << words1[i] << ' ' << words2[i] << endl;
                return false;
            }
        }
        
        return true;
    }
private:
    int get_word_id(const string& word) {
        if (dict.count(word) == 0) {
            dict[word] = idx++;
        }
        return dict[word];
    }
private:
    int idx;
    map<string, int> dict;
    DisjointSet ds;
};
