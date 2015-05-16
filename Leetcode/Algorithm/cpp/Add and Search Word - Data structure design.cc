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
    
    unordered_map<char, TrieNode*>& internal_mp() {
        return _mp;
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
    void insert(const string& s) {
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
    
    bool wildcard_search(string key) {
        int n = key.size();
        auto ptr = wildcard_find(root, key, 0, n);
        
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
    
    TrieNode* wildcard_find(TrieNode* root, const string& s, int idx, int n) {
        auto ptr = root;
        for (int i = idx; i < n; i++) {
            char c = s[i];
            if (c != '.') {
                ptr = ptr->next(c);
                if (ptr == nullptr) {
                    return nullptr;
                }
            } else {
                auto& mp = ptr->internal_mp();
                for (auto pp: mp) {
                    auto p = wildcard_find(pp.second, s, i + 1, n);
                    if (p != nullptr && p->is_end()) {
                        return p;
                    }
                }
                return nullptr;
            }
        }
        return ptr;
    }

private:
    TrieNode* root;
};


class WordDictionary {
public:
    // Adds a word into the data structure.
    void addWord(string word) {
        _trie.insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return _trie.wildcard_search(word);
    }
private:
    Trie _trie;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
