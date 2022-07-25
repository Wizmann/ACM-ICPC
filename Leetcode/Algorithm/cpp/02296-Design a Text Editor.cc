class TextEditor {
public:
    TextEditor() {
        iter = chars.end();
    }
    
    void addText(string text) {
        iter = chars.insert(iter, text.begin(), text.end());
        int n = text.size();
        for (int i = 0; i < n; i++) {
            ++iter;
        }
        print("addText");
    }
    
    int deleteText(int k) {
        auto jter = iter;
        int step = 0;
        for (int i = 0; i < k; i++) {
            if (jter != chars.begin()) {
                step++;
                --jter;
            } else {
                break;
            }
        }
        chars.erase(jter, iter);
        print("deleteText");
        return step;
    }
    
    string cursorLeft(int k) {
        string res;
        for (int i = 0; i < k; i++) {
            if (iter != chars.begin()) {
                --iter;
            }    
        }
        
        auto jter = iter;
        for (int i = 0; i < 10; i++) {
            if (jter == chars.begin()) {
                break;
            }
            --jter;
            if (res.size() < 10) {
                res.push_back(*jter);
            } else {
                break;
            }
        }
        
        reverse(res.begin(), res.end());
        print("cursorLeft");
        return res;
    }
    
    string cursorRight(int k) {
        string res;
        for (int i = 0; i < k; i++) {
            if (iter != chars.end()) {
                iter++;
            }
        }
        auto jter = iter;
        for (int i = 0; i < 10; i++) {
            if (jter == chars.begin()) {
                break;
            }
            --jter;
            if (res.size() < 10) {
                res.push_back(*jter);
            } else {
                break;
            }
        }
        
        reverse(res.begin(), res.end());
        print("cursorRight");
        return res;
    }
    
    void print(const string& caller) {
        /*
        string s;
        for (auto c : chars) {
            s.push_back(c);
        }
        cout << caller << ": " << s << ' ' << distance(chars.begin(), iter) << endl;
        */
    }
private:
    list<char> chars;
    list<char>::iterator iter;
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
