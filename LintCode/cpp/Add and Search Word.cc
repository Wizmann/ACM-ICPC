const int ALPHA = 26;

class Trie {
private:
    struct TrieNode {
        TrieNode() {
            is_end = false;
            next = vector<int>(ALPHA, -1);
        }
        bool is_end;
        vector<int> next;
    };
public:
    void init() {
        do_append();
    }
    void add(const string& str) {
        do_add(str, 0, 0);
    }
    bool search(const string& str) {
        return do_search(str, 0, 0);
    }
private:
    void do_append() {
        _nodes.push_back(TrieNode());
        idx = _nodes.size() - 1;
    }
    void do_add(const string& str, int ptr, int pos) {
        if (str.size() == ptr) {
            _nodes[pos].is_end = true;
            return;
        }
        int cur = str[ptr] - 'a';
        if (_nodes[pos].next[cur] == -1) {
            do_append();
            _nodes[pos].next[cur] = idx;
        }
        pos = _nodes[pos].next[cur];
        do_add(str, ptr + 1, pos);
    }
    bool do_search(const string& str, int ptr, int pos) {
        if (str.size() == ptr) {
            return _nodes[pos].is_end;
        }
        char cur_c = str[ptr];

        if (cur_c == '.') {
            for (auto next: _nodes[pos].next) {
                if (next == -1) {
                    continue;
                }
                if (do_search(str, ptr + 1, next)) {
                    return true;
                }
            }
            return false;
        }
        
        int cur = cur_c - 'a';
        int next = _nodes[pos].next[cur];
        
        if (next == -1) {
            return false;
        }
        return do_search(str, ptr + 1, next);
    }
private:
    int idx;
    vector<TrieNode> _nodes;
};

class WordDictionary {
public:
    WordDictionary() {
        _trie.init();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        _trie.add(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return _trie.search(word);
    }
private:
    Trie _trie;
};


// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
