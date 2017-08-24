// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int conv(char c) {
    switch (c) {
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;
    }
    return -1;
}

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    int n = S.size();
    
    vector<int> v[4];
    
    for (int i = 0; i < 4; i++) {
        v[i].resize(n);
    }
    
    for (int i = 0; i < n; i++) {
        char c = S[i];
        int u = conv(c);
        
        for (int j = 0; j < 4; j++) {
            v[j][i] += i - 1 >= 0? v[j][i - 1]: 0;
            if (j == u) {
                v[j][i] += 1;
            }
        }
    }
    
    int m = P.size();
    vector<int> res;
    for (int i = 0; i < m; i++) {
        int p = P[i];
        int q = Q[i];
        
        for (int j = 0; j < 4; j++) {
            int cnt = v[j][q] - (p - 1 >= 0? v[j][p - 1]: 0);
            if (cnt) {
                res.push_back(j + 1);
                break;
            }
        }
    }
    return res;
}
