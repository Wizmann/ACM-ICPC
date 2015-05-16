class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode(): _mp(unordered_map<char, TrieNode*>()), \
                _endpoint(false) {}
    
    TrieNode* next(char c) {
        auto iter = _mp.find(c);
        if (iter == _mp.end()) {
            return nullptr;
        }
        return iter->second;
    }
    
    bool is_end() {
        return _endpoint;
    }
    
    bool set_end() {
        _endpoint = true;
    }
    
    void add(char c) {
        _mp[c] = new TrieNode();
    }
private:
    unordered_map<char, TrieNode*> _mp;
    bool _endpoint;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        auto ptr = root;
        for (auto c: s) {
            if (ptr->next(c) == nullptr) {
                ptr->add(c);
            }
            ptr = ptr->next(c);
        }
        ptr->set_end();
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        auto ptr = find(key);
        if (ptr == nullptr) {
            return false;
        }
        return ptr->is_end();
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        auto ptr = find(prefix);
        if (ptr == nullptr) {
            return false;
        }
        return ptr != nullptr;
    }
    
private:
    TrieNode* find(string s) {
        auto ptr = root;
        for (char c: s) {
            ptr = ptr->next(c);
            if (!ptr) {
                return nullptr;
            }
        }
        return ptr;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
