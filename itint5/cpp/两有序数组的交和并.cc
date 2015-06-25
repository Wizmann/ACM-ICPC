class UniqueSortedVector {
public:
    void push_back(int u) {
        if (!vec.empty() && u == *vec.rbegin()) {
            return;
        }
        vec.push_back(u);
    }
    vector<int>& Vector() {
        return vec;
    }
private:
    vector<int> vec;
};

vector<int> arrayUnion(vector<int> &a, vector<int> &b) {
    UniqueSortedVector usv;
    int n = a.size();
    int m = b.size();
    
    int i = 0;
    int j = 0;
    
    for (i = 0, j = 0; i < n || j < m; /* pass */) {
        if (j >= m || (i < n && a[i] < b[j])) {
            usv.push_back(a[i++]);    
        } else {
            usv.push_back(b[j++]);
        }
    }
    return usv.Vector();
}

vector<int> arrayIntersect(vector<int> &a, vector<int> &b) {
    UniqueSortedVector usv;
    int n = a.size();
    int m = b.size();
    
    int i = 0;
    int j = 0;
    
    for (i = 0, j = 0; i < n && j < m; /* pass */) {
        if (a[i] == b[j]) {
            int u = a[i];
            usv.push_back(u);
            i++;
            j++;
        } else {
            if (a[i] < b[j]) {
                i++;
            } else {
                j++;
            }
        }
    }
    return usv.Vector();
}
