int n;

struct Node {
    int l, r;
    
    bool operator < (const Node& other) const {
        if (dis() != other.dis()) {
            return dis() > other.dis();
        }
        if (l != other.l) { 
            return l < other.l; 
        }
        return r < other.r;
    }
    
    int dis() const {
        if (l == -1) {
            return r;
        } else if (r == n) {
            return n - 1 - l;
        }
        return (r - l) / 2;
    }
};

class ExamRoom {
public:
    ExamRoom(int N) {
        st.insert(-1);
        st.insert(N);
        n = N;
        nodes.insert({-1, N});
    }
    
    int seat() {
        auto cur = *nodes.begin();
        nodes.erase(nodes.begin());
        int l = cur.l;
        int r = cur.r;
        
        int m = (l + r) >> 1;
        
        if (l == -1) {
            m = 0;
        } else if (r == n) {
            m = n - 1;
        }
        
        st.insert(m);
        nodes.insert({l, m});
        nodes.insert({m, r});
        return m;
    }
    
    void leave(int p) {
        auto iter = st.find(p);
        int l = *prev(iter);
        int r = *next(iter);
                
        st.erase(iter);
        
        Node node1 = {l, p};
        Node node2 = {p, r};
        
        nodes.erase(nodes.find(node1));
        nodes.erase(nodes.find(node2));
        nodes.insert({l, r});
    }
private:
    set<int> st;
    set<Node> nodes;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
