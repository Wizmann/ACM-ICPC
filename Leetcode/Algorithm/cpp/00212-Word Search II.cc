const int mx[] = {0, 1, 0, -1};
const int my[] = {1, 0, -1, 0};

class Trie {
public:
    void insert(const string& str, int nr) {
        do_insert(str.c_str(), 0, nr);
    }
    
    void clear() {
        idx = 0;
        memset(_nodes, -1, sizeof(_nodes));
    }
    
    bool is_end(int pos) {
        return _nodes[pos].end != -1;
    }
    
    int get_str(int pos) {
        int nr = _nodes[pos].end;
        return nr;
    }
    
    int next(int pos, char c) {
        return _nodes[pos].next[c - 'a'];
    }
private:
    void do_insert(const char* str, int pos, int nr) {
        if (*str == '\0') {
            _nodes[pos].end = nr;
            return;
        }
        if (_nodes[pos].next[*str - 'a'] == -1) {
            _nodes[pos].next[*str - 'a'] = ++idx;
        }
        int next = _nodes[pos].next[*str - 'a'];
        do_insert(str + 1, next, nr);
    }
private:
   struct TrieNode {
       int next[26];
       int end;
   };
   
   int idx;
   TrieNode _nodes[80000];
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        trie = new Trie();
        trie->clear();
        int word_num = words.size();
        for (int i = 0; i < word_num; i++) {
            trie->insert(words[i], i);
        }
        res.clear();
        n = board.size();
        m = board[0].size();
        
        visit.resize(n);
        for (auto& line: visit) {
            line.resize(m);
            fill(line.begin(), line.end(), 0);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dfs(board, i, j, 0);
            }
        }
        delete(trie);
        
        vector<string> res_;
        for_each(res.begin(), res.end(), [&](const int idx) {
            res_.push_back(words[idx]);
        });
        return res_;
    }
private:
    void dfs(vector<vector<char>>& board, int y, int x, int pos) {
        visit[y][x] = 1;
        do {
            char c = board[y][x];
            int next = trie->next(pos, c);
            if (next == -1) {
                break;
            }
            
            if (trie->is_end(next)) {
                res.insert(trie->get_str(next));
            }
            
            for (int i = 0; i < 4; i++) {
                int ny = y + my[i];
                int nx = x + mx[i];
                
                if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
                    if (!visit[ny][nx]) {
                        dfs(board, ny, nx, next);
                    }
                }
            }
        } while (0);
        visit[y][x] = 0;
    }
private:
    int n, m;
    Trie *trie;
    set<int> res;
    vector<vector<char> > visit;
};
