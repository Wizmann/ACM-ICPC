template <int ALPHABET, int NODE_SIZE>
class ACAutomation {
public:
    void insert(const string& str, int nr) {
        int p = ROOT;
        for (int i = 0; i < str.size(); i++) {
            int c = str[i];
            if (!trie[p].next[c]) {
                trie[p].next[c] = ++tail;
            }
            p=trie[p].next[c];
        }
        trie[p].frq++;
        trie[p].end=nr;
    }

    void makeAC() {
        queue<int> q;
        for (int i = 0; i < ALPHABET; i++) {
            if (trie[ROOT].next[i]) {
                trie[trie[ROOT].next[i]].fail = ROOT;
                q.push(trie[ROOT].next[i]);
            }
        }
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            for (int i=0; i < ALPHABET; i++) {
                if (trie[p].next[i]) {
                    int v = trie[p].next[i];
                    q.push(v);
                    trie[v].fail = trie[trie[p].fail].next[i];
                } else {
                    trie[p].next[i] = trie[trie[p].fail].next[i];
                }
            }
        }
    }

    int find(int p, char c, vector<int>& matched) {
        while (trie[p].fail && !trie[p].next[c]) {
            p = trie[p].fail;
        }
            
        p = trie[p].next[c];
        int t = p;
        while (t) {
            if (trie[t].end) {
                matched.push_back(trie[t].end);
            }
            t = trie[t].fail;
        }
        return p;
    }

    void clear() {
        memset(trie, 0, sizeof(trie));
        tail = 0;
    }
private:
    struct node {
        int next[ALPHABET];
        int fail;
        int frq;
        int end; 
    };

    int tail = 0;
    node trie[NODE_SIZE];
public:
    const int ROOT = 0;
};


ACAutomation<128, 30000> ac;

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        ac.clear();
        int idx = 1;
        for (const auto& word: words) {
            ac.insert(word, idx++);
        }
        ac.makeAC();
        p = ac.ROOT;
    }
    
    bool query(char letter) {
        vector<int> matched;
        p = ac.find(p, letter, matched);
        return !matched.empty();
    }
private:
    int p;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
